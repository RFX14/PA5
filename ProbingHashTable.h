#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"

// Linear probing hash table class
class ProbingHashTable : public HashTable {
    private:
    // TODO: insert additional variables here
        std::vector<std::string> table;
        std::vector<int> count;
    public: 
        ProbingHashTable(std::string str);
        ~ProbingHashTable(); 
        void insert(std::string key, int val); 
        int remove(std::string key); 
        int get(std::string key); 
        void printAll(std::string filename);
};

#endif