#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node {
    string key;
    Node* next;
    
    Node(string k) : key(k), next(nullptr) {}
};

class HashTable {
    private:
        Node** table;
        int size;
        
        int hash_function(string key);
        
    public:
        HashTable(int tableSize);
        
        void insert(string key);
        void printFirstNSlots(int n);
        void printSlotLengths();
        double printStdDev();
    };