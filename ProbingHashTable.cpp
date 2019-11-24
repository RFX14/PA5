#include "ProbingHashTable.h"

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable(std::string str) : HashTable(str) {
	table.resize(58000);
	count.resize(58000);
	for(int i = 0; i < data.size(); i++) {
		insert(data.at(i), HashTable::hash(data.at(i)));
	}
}

// destructor
ProbingHashTable::~ProbingHashTable() {
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	std::cout << key << "\n";
	bool placed = false;
	for(int i = 0; i < data.size() - 100; i++) {
		int newVal = (HashTable::hash(key) + i) % (data.size() - 5);
		if(table.at(newVal) == "" || table.at(newVal) == key) {
			table.at(newVal) = key;
			count.at(newVal) += 1;
			placed = true;
			break;
		} 
	}

	if(!placed) { std::cout << "ERROR: Table Full!\n"; }
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int val = HashTable::hash(key);
	if(table.at(val) == "" || count.at(val) == 0) {
		std::cout << "ERROR: Key doesn't exist\n";
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
	if(table.at(val) == "") {
		std::cout << "ERROR: Key doesn't exist\n";
		return 0;
	}
	return val;
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