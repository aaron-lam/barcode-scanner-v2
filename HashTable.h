/**
 * This is the header file for Hash Table
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

const int CAPACITY = 1000;

template<class K, class V>
struct KeyValuePair {
    K key;
    V value;
    
    KeyValuePair(K key, V value) : 
            key(key), value(value) {}
};

template<class K, class V>
struct Node {
    KeyValuePair<K, V> rec;
    Node<K, V> *next;

    Node(const KeyValuePair<K, V> &rec, Node<K, V> *next) : 
            rec(rec), next(next) {}
};

template<class K, class V>
class HashTable {
public:
    HashTable();

    void insert(K key, V value);

    V find(K key) const;

private:
    int hash(K key) const;

    void find(K key, bool &found, Node<K, V> *&ptr) const;

    Node<K, V> *table[CAPACITY];
};

#endif
