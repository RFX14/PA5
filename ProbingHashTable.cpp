#include "ProbingHashTable.h"

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable(std::string str) : HashTable(str) {
	table.resize(58110);
	count.resize(58110);
	try {
		std::cout << "Inserting...\n";
		for(int i = 0; i < data.size(); i++) {
			insert(data.at(i), HashTable::hash(data.at(i)));
		}
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
	if(table.at(val) == "" || count.at(val) == 0) {
		std::cout << "ERROR: Key Doesn't Exist\n";
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
	while(i < table.size() && table.at(val) != "") {
		val = (val + i) % table.size();
		if(table.at(val) == key) {
			return val;
		}
		i++;
	}
	std::cout << "ERROR: Key Doesn't Exist\n";
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
	for(int i = 0; i < table.size(); i++) {
		if(table.at(i) != "") {
			std::cout << i  << ": " << table.at(i) << ": " << count.at(i) << '\n';
		}
	}
}