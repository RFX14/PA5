#include <iostream>
#include "HashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"

using namespace std;

int main() {
    DoubleHashTable myTable("dictionary.txt");
    myTable.printAll("DoubleHashing.txt");

    ProbingHashTable myTable2("dictionary.txt");
    myTable2.printAll("Probing.txt");

    ChainingHashTable myTable3("dictionary.txt");
    myTable3.printAll("Chaining.txt");
    return 0;
}