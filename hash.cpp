#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

// Initializes the hash table to a given size and sets all pointers in the table to nullptr
HashTable::HashTable(int tableSize) {
    size = tableSize;
    table = new Node*[size];

    // Sets all the slots to nullptr to start the table
    int i = 0;
    for (i; i < size; i++) {
        table[i] = nullptr;
    }
}

// Hash function that will assign a key to a slot
int HashTable::hash_function(string text) {
    // Implement your own hash function here
    char first = text[0];

    // if the first letter is a capital letter, then it will convert it into a lowercase for the sake of unifomity
    if (first >= 'A' && first <= 'Z') {
        first = first - 'A' + 'a';
    }

    // Sets the character to be able to fit a base 0 array or in this case linked list
    int index = first - 'a';

    // wraps the slots if index is greater than the size 
    return (index % size);
}

// Adds the key at the index of the table at the beginning
void HashTable::insert(string key) {
    int index = hash_function(key);

    // Adds the key to the beginning of the slot
    Node* current = new Node(key);
    current->next = table[index];
    table[index] = current;
}

// Prints the number of lines that the user inputs, showing the keys at each slot
void HashTable::printFirstNSlots(int n) {

    // Reads the keys in the i slot until the nth slot and prints out each key
    for (int i = 0; i < n; i++) {
        cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << current-> key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Prints all the slots and how many keys are held at each slot
void HashTable::printSlotLengths() {

    // Increments a variable length that keeps track of the length of each slot and is printed after each slot and their # of keys are accounted for
    for (int i = 0; i < size; i++) {
        cout << "Slot " << i << ": ";
        int length = 0;
        Node* current = table[i];
        while (current != nullptr) {
            length += 1;
            current = current->next;
        }
        cout << length << endl;
    }
}

// Calculates the standard deviation by finding all the length of each slot and their mean and then dividing by the size, then square rooting it to find the standard deviation
double HashTable::printStdDev() {
    double mean = 0.0;
    double cummulative = 0.0;
    double n = (double)size;
    double* deviation = new double[size];
    double variation = 0.0;

    // Gets the sum of all the slot lengths
    for (int i = 0; i < size; i++) {
        double length = 0;
        Node* current = table[i];
        while (current != nullptr) {
            length += 1.0;
            current = current->next;
        }
        cummulative += length;
        deviation[i] = length;
    }

    // Gets the mean of the table
    mean = cummulative / n;

    // Calculates how far each slot length is from the mean and squares it
    for (int i = 0; i < size; i++) {
        variation += pow(deviation[i] - mean, 2);
    }

    // Divided by the size of the table
    variation = variation / n; 

    // Square rooted to find the deviation
    variation = sqrt(variation);

    cout << variation << endl;

    delete[] deviation;

    return variation;
}