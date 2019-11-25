#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "HashTable.h"


// Double hashing hash table class
class DoubleHashTable : public HashTable {
    private:
    // helper functions
        int secondHash(std::string s);

    // TODO: insert additional variables here
        std::vector<std::string> table;
        std::vector<int> count;
    public: 
        DoubleHashTable(std::string str);
        ~DoubleHashTable(); 
        void insert(std::string key, int val); 
        int remove(std::string key); 
        int get(std::string key); 
        void printAll(std::string filename);
};

#endif