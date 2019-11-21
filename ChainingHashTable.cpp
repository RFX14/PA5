#include "ChainingHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable(std::string str) : HashTable(str) {
	table.reserve(58000);
	for(int i = 0; i < data.size(); i++) {
		insert(data.at(i), HashTable::hash(data.at(i)));
	}
}

// destructor
ChainingHashTable::~ChainingHashTable() {
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	table.at(val) = key;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	if(table.at(HashTable::hash(key)) == " ") {
		std::cout << "ERROR: Key doesn't exist\n";
		return 0;
	}
	table.at(HashTable::hash(key)) = " ";
	return HashTable::hash(key);
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	return HashTable::hash(key);
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

}