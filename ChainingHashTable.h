#ifndef CHAINING_H
#define CHAINING_H

#include "HashTable.h"
#include <string>

// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
    // TODO: insert additional variables needed here
        std::vector<int> table;
        std::vector<int> count;
    public: 
        ChainingHashTable(std::string str);
        ~ChainingHashTable() = default; 
        void insert(std::string key, int val); 
        int remove(std::string key); 
        int get(std::string key);
        void printAll(std::string filename);
};

#endif