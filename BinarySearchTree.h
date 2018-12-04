/**
 * This is the header file for Binary Search Tree
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <iostream>

using namespace std;

template<class T>
struct node {
    T data;
    node<T> *left;
    node<T> *right;
};

template<class T>
class BinarySearchTree {

public:
    BinarySearchTree();

    void printInOrder() { printInOrder(root); }

    void printPreOrder() { printPreOrder(root); }

    void printPostOrder() { printPostOrder(root); }

    int height() { return height(root); }

    void insert(T &item) { insert(root, item); }

    bool search(T &item) { return search(root, item); }

    T find(T &e, const string& key) { return find(root, key, e); }

    T findMax(T &e) { return findMax(root, e); }

    T findMin(T &e) { return findMin(root, e); }

    void deletenode(T &item) { deleteNode(root, item); }

    ~BinarySearchTree() { destroy(root); }

private:
    node<T> *root;

    void printInOrder(node<T> *);

    void printPreOrder(node<T> *);

    void printPostOrder(node<T> *);

    void destroy(node<T> *);

    int height(node<T> *);

    int max(int, int);

    void insert(node<T> *&, T &);

    bool search(node<T> *, T &);

    T find(node<T> *p, const string &key, T &e);

    T findMax(node<T> *, T &);

    T findMin(node<T> *, T &);

    void deleteNode(node<T> *&, T &);
};


#endif
