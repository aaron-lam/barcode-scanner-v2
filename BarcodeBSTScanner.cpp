/**
 * This is an implementation file of the barcode Binary Search Tree Scanner.
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include <fstream>
#include "BarcodeBSTScanner.h"

/**
 * Constructor.
 */
BarCodeBSTScanner::BarCodeBSTScanner(const string& fileName) {
    ifstream infile(fileName);
    string upc, description;
    string info;
    while (getline(infile, info)) {
        upc = info.substr(0, info.find(','));
        description = info.substr(info.find(',') + 1);
        Barcode barcode(upc, description);
        tree.insert(barcode);
    }
}

/**
 * Return the corresponding barcode with the upc number
 */
Barcode BarCodeBSTScanner::find(const string &upc) {
    Barcode dummy;
    return tree.find(dummy, upc);
}
