/**
 * This is the header file of the barcode Binary Search Tree Scanner.
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef BARCODE_BST_SCANNER_H
#define BARCODE_BST_SCANNER_H

#include <sstream>

#include "Barcode.h"
#include "BinarySearchTree.cpp";

class BarCodeBSTScanner {
public:
    BarCodeBSTScanner(const string& fileName);

    Barcode find(const string& upc);
private:
    BinarySearchTree<Barcode> tree;
};


#endif
