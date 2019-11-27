#include "HashTable.h"
#include <string>

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////
HashTable::HashTable(std::string str) {
	std::ifstream file{str};
	std::string input;
	while(file >> input) {
		data.push_back(input);
	}
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {
	int hash = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		//std::cout << hash << '\n';
		hash = 2 * hash + int(s.at(i));
	}
	//std::cout << hash % 58000 << '\n';
	return (hash % 58110);
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	if(data.size() == 0) {
		return true;
	}

	return false;
}