#include "ChainingHashTable.h"
#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable(std::string str) : HashTable(str) {
	for(int i = 0; i < data.size(); i++) {
		insert(data.at(i), HashTable::hash(data.at(i)));
	}
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	//std::cout << key << "\n";
	table.push_back(val);
	//std::cout << "After\n\n";
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
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
int ChainingHashTable::get(std::string key) {
	int val = HashTable::hash(key);
	if(table.at(val) == "") {
		std::cout << "ERROR: Key doesn't exist\n";
		return 0;
	}
	return val;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
	for(int i = 0; i < table.size(); i++) {
		if(table.at(i) != "") {
			std::cout << i  << ": " << table.at(i) << ": " << count.at(i) << '\n';
		}
	}
}