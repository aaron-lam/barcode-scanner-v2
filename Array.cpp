/**
 * This is the implementation file of the array class
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include "Array.h"

/**
 * The default constructor which initialize the list with size 10.
 */
template <class T>
Array<T>::Array() {
    size = 0;
    capacity = 10;
    list = new T[10];
}

/**
 * Push the info item in the back of the list.
 * If the size of the list meets the capacity of the list,
 * double the capacity of the list.
 */
template <class T>
void Array<T>::push_back(const T& item) {
    // double the capacity if needed
    if (size == capacity) {
        reserve(2 * capacity);
    }
    list[size] = item;
    size = size + 1;
}

/**
 * Erase the the info item in the list.
 * If the size of the list is the half of the capacity of the list,
 * divide the capacity of the list by two.
 */
template <class T>
void Array<T>::erase(int index) {
    // After deletion, shift all right elements to the left by one
    for (int i = index + 1; i < size; i++) {
        list[i - 1] = list[i];
    }
    size = size - 1;
    // divide the capacity in half if needed
    if (size < capacity / 2) {
        reserve(capacity / 2);
    }
}

/**
 * Copy all elements from old list to new list.
 * Replace the old list with new list with updated capacity.
 */
template <class T>
void Array<T>::reserve(int n) {
    auto *newList = new T[n];
    // Copy the elements from old list to new list
    for (int i = 0; i < size; i++) {
        newList[i] = list[i];
    }
    // release the memory of the old list
    delete[] list;
    // replace the new list and update the capacity
    list = newList;
    capacity = n;
}

template <class T>
int Array<T>::getSize() const {
    return size;
}

template <class T>
T& Array<T>::operator[](int i) const {
    return list[i];
}
