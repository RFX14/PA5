#include "DoubleHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable(std::string str) : HashTable(str) {
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
DoubleHashTable::~DoubleHashTable() {

}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
	//std::cout << key << "\n";
	bool placed = false;
	for(int i = 0; i < table.size(); i++) {
		if(table.at(val) == "" || table.at(val) == key) {
			table.at(val) = key;
			count.at(val) += 1;
			placed = true;
			break;
		}
		val = (val + i * secondHash(key)) % table.size();
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
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
int DoubleHashTable::get(std::string key) {
	int i = 0;
	int val = HashTable::hash(key);
	while(i < table.size() && table.at(val) != "") {
		if(table.at(val) == key) {
			return val;
		}
		val = (val + i * secondHash(key)) % table.size();
		i++;
	}
	return 0;
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
	for(int i = 0; i < table.size(); i++) {
		if(table.at(i) != "") {
			std::cout << i  << ": " << table.at(i) << ": " << count.at(i) << '\n';
		}
	}
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {
	int hash = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		//std::cout << hash << '\n';
		hash = 1 + ((int)s.at(i) % table.size() - 1);
	}
	//std::cout << hash % 58000 << '\n';
	return (hash % 58000);
}
