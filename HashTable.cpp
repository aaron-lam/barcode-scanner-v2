/**
 * This is the implementation file for Hash Table
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include <cstdlib>
#include <string>

using namespace std;

#include "HashTable.h"

/**
 * Constructor.
 */
template<class K, class V>
HashTable<K, V>::HashTable() {
    for (auto &node : table) {
        node = NULL;
    }
}

/**
 * Insert a new key-value pair to the table.
 */
template<class K, class V>
void HashTable<K, V>::insert(K key, V value) {
    bool isExist = false;
    Node<K, V> *node;
    KeyValuePair<K, V> newValuePair(key, value);

    find(newValuePair.key, isExist, node);
    if (!isExist) {
        // get the index of "bucket" where newValuePair belongs
        int i = hash(newValuePair.key);
        // insert at beginning of list
        auto *temp = new Node<K, V>(newValuePair, table[i]);
        table[i] = temp;
    } else {
        // node points to existing record that should be updated
        node->rec = newValuePair;
    }
}

/**
 * Hashing function.
 */
template<class K, class V>
int HashTable<K, V>::hash(K key) const {
    try {
        // hash the upc number based on the manufacturer number
        int intKey = stoi(key.substr(1, 6));
        return intKey % CAPACITY;
    } catch (exception& e) {
    }
    return 0;
}

/**
 * The helper method of function find.
 */
template<class K, class V>
void HashTable<K, V>::find(K key, bool &found, Node<K, V> *&nodePtr) const {
    int hashedKey = hash(key);
    Node<K, V> *tableHead = table[hashedKey];
    while (!found && tableHead != NULL) {
        if (key == tableHead->rec.key) {
            found = true;
            nodePtr = tableHead;
        }
        tableHead = tableHead->next;
    }
    if (!found) {
        nodePtr = NULL;
    }
}

/**
 * Return the value based on the key.
 */
template<class K, class V>
V HashTable<K, V>::find(K key) const {
    bool found = false;
    Node<K, V> *nodePtr;
    find(key, found, nodePtr);
    if (found) {
        return (nodePtr->rec).value;
    }
}
