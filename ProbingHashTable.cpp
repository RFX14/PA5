#include "ProbingHashTable.h"
#include <fstream>
#include <iterator>
#include <vector>
#include <chrono>

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable(std::string str) : HashTable(str) {
	table.resize(58110);
	count.resize(58110);
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
			std::ofstream output_file("Linear.csv");
		
		for(int i = 0; i < time.size(); i++) {
			output_file << time.at(i).count() << ",\n";
		}
		output_file.close();
	} catch(...) {
		std::cout << "ERROR: Insert Failed!\n";
	}	
}

// destructor
ProbingHashTable::~ProbingHashTable() {
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	//std::cout << key << "\n";
	bool placed = false;
	for(int i = 0; i < table.size(); i++) {
		if(table.at(val) == "" || table.at(val) == key) {
			table.at(val) = key;
			count.at(val) += 1;
			placed = true;
			break;
		} 
		val = (val + i) % table.size();
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int val = get(key);
	if(table.at(val) == "" || count.at(val)) {
		//std::cerr << "ERROR: Key Doesn't Exist\n";
		return 0;
	}
	
	count.at(val) -= 1;
	if(count.at(val) == 0) {
		table.at(val) = "";
	}
	return val;
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {
	int val = HashTable::hash(key);
	int i = 0;
	bool found = false;
	while(i < table.size() && table.at(val) != "") {
		val = (val + i) % table.size();
		if(table.at(val) == key) {
			found = true;
			return val;
		}
		i++;
	}
	if(!found) {
		//std::cerr << "ERROR: Key Doesn't Exist\n";
	}
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
	std::ofstream myFile{filename};
	for(int i = 0; i < table.size(); i++) {
		if(table.at(i) != "") {
			myFile << table.at(i) << ": " << count.at(i) << '\n';
		}
	}
}