#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////
// default constructor
HashTable::HashTable() {

}

// destructor
HashTable::~HashTable() {
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {
	int hash = 0;
	int n = s.length();
	for(int i = 0; i < n; i++) {
		hash = g * hash + s.at(i);
	}
	return hash % 101;
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	
	return false;
}
