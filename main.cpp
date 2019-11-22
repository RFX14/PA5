#include <iostream>
#include "HashTable.h"
#include "ChainingHashTable.h"

using namespace std;

int main() {
    ChainingHashTable myTable("dictionary.txt");
    myTable.printAll("testOut.txt");
    return 0;
}