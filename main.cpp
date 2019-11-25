#include <iostream>
#include "HashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

using namespace std;

int main() {
    DoubleHashTable myTable("dictionary.txt");
    myTable.printAll("testOut.txt");
    return 0;
}