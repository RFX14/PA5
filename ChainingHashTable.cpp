#include "ChainingHashTable.h"
#include "HashTable.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <chrono>

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable(std::string str) : HashTable(str) {
	table.resize(58110);
	std::vector<std::chrono::nanoseconds> time;
	try {
		std::cout << "Inserting...\n";
		auto start = std::chrono::high_resolution_clock::now();
		for(int i = 0; i < data.size(); i++) {
			if(i % 10000 == 0 && i != 0) {
				insert(data.at(i), HashTable::hash(data.at(i)));
				auto finish = std::chrono::high_resolution_clock::now();
            	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
				time.push_back(elapsed);
            	start = std::chrono::high_resolution_clock::now();
			} else {
				insert(data.at(i), HashTable::hash(data.at(i)));
			}
		}
		std::cout << "DONE!\n";
			std::ofstream output_file("Chain.csv");
		
		for(int i = 0; i < time.size(); i++) {
			output_file << time.at(i).count() << ",\n";
		}
		output_file.close();
	} catch(...) {
		std::cout << "ERROR: Insert Failed!\n";
	}
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	//std::cout << key << "\n";
	table.at(val).push_back(key);
	//std::cout << "After\n\n";
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int val = HashTable::hash(key);
	if(table.at(val).size() == 0) {
		//std::cerr << "ERROR: Key doesn't exist\n";
		return 0;
	}

	table.at(val).pop_back();
	return val;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	int val = HashTable::hash(key);
	if(table.at(val).size() == 0) {
		//std::cerr << "ERROR: Key doesn't exist\n";
		return 0;
	}
	return val;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
	std::ofstream myFile(filename);
	for(int i = 0; i < table.size(); i++) {
		if(table.at(i).size() != 0) {
			myFile << table.at(i).at(0) << ": " << table.at(i).size() << '\n';
		}
	}
}