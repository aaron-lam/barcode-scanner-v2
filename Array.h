/**
 * This is the header file of the array class
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

template <class T>
class Array {
public:
    Array();

    void push_back(const T &item);

    void erase(int index);

    void reserve(int n);

    int getSize() const;

    T &operator[](int i) const;

private:
    int capacity;
    int size;
    T *list;
};


#endif
