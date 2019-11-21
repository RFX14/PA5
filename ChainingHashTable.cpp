#include "ChainingHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable(std::string str) : HashTable(str) {
	for(int i = 0; i < data.size(); i++) {
		insert(data.at(i), HashTable::hash(data.at(i)));
	}
}

// destructor
ChainingHashTable::~ChainingHashTable() {

}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {

	return 0;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

}