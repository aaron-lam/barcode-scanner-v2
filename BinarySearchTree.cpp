/**
 * This is the implementation file for Binary Search Tree
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include "BinarySearchTree.h"

template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = NULL;
}

template<class T>
void BinarySearchTree<T>::printInOrder(node<T> *p) {
    if (p != NULL) {
        printInOrder(p->left);
        cout << p->data << " ";
        printInOrder(p->right);
    }
}

template<class T>
void BinarySearchTree<T>::printPreOrder(node<T> *p) {
    if (p != NULL) {
        cout << p->data << " ";
        printPreOrder(p->left);
        printPreOrder(p->right);
    }
}

template<class T>
void BinarySearchTree<T>::printPostOrder(node<T> *p) {
    if (p != NULL) {
        printPostOrder(p->left);
        printPostOrder(p->right);
        cout << p->data << " ";
    }
}

template<class T>
int BinarySearchTree<T>::max(int x, int y) {
    return x > y ? x : y;
}

template<class T>
int BinarySearchTree<T>::height(node<T> *p) {
    if (p != NULL) {
        return 1 + max(height(p->left), height(p->right));
    }
    return -1;
}

template<class T>
void BinarySearchTree<T>::destroy(node<T> *p) {
    if (p != NULL) {
        destroy(p->left);
        destroy(p->right);
        p = NULL;
        delete p;
    }
}

template<class T>
void BinarySearchTree<T>::insert(node<T> *&p, T &item) {
    if (p == NULL) {
        p = new node<T>;
        p->data = item;
        p->left = p->right = NULL;
    } else if (p->data < item) {
        insert(p->left, item);
    } else {
        insert(p->right, item);
    }
}

template<class T>
bool BinarySearchTree<T>::search(node<T> *p, T &item) {
    if (p == NULL) {
        return false;
    }
    if (item < p->data) {
        return search(p->left, item);
    }
    if (item > p->data) {
        return search(p->right, item);
    }
    return true;
}

/**
 * Return the data of the node if it matches the given key.
 */
template<class T>
T BinarySearchTree<T>::find(node<T> *p, const string &key,  T &e) {
    if (p == NULL) {
        return e;
    }
    if (p->data == key) {
        return p->data;
    }
    if (p->data < key) {
        return find(p->right, key, e);
    } else {
        return find(p->left, key, e);
    }
}

template<class T>
T BinarySearchTree<T>::findMax(node<T> *p, T &e) {
    if (p == NULL) {
        return e;
    }
    if (p->right == NULL) {
        return p->data;
    }
    return findMax(p->right, e);
}

template<class T>
T BinarySearchTree<T>::findMin(node<T> *p, T &e) {
    if (p == NULL) {
        return e;
    }
    if (p->left == NULL) {
        return p->data;
    }
    return findMin(p->left, e);
}

template<class T>
void BinarySearchTree<T>::deleteNode(node<T> *&p, T &item) {
    //item not found, do nothing
    if (p == NULL) {
        return;
    } else if (item < p->data) {    //item is on the left subtree
        deleteNode(p->left, item);
    } else if (item > p->data) {    //item is on the right subtree
        deleteNode(p->right, item);
    } else {                        //item is equal to value, it is found
        if (p->left != NULL && p->right != NULL) { // with two children
            int e = -1;
            p->data = findMax(p->left, e);
            deleteNode(p->left, p->data);
        } else {
            node<T> *old = p;
            p = (p->left != NULL) ? p->left : p->right;
            delete old;
        }
    }
}
