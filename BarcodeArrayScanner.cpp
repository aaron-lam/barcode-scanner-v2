/**
 * This is the implementation file of Barcode Array Scanner
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include "BarcodeArrayScanner.h"

/**
 * Constructor.
 */
BarcodeArrayScanner::BarcodeArrayScanner(const string& fileName) {
    ifstream infile(fileName);
    string upc, description;
    string info;
    while (getline(infile, info)) {
        upc = info.substr(0, info.find(','));
        description = info.substr(info.find(',') + 1);
        Barcode barcode(upc, description);
        array.push_back(barcode);
    }
}

/**
 * Return the corresponding barcode with the upc number
 */
Barcode BarcodeArrayScanner::find(const string &upc) {
    Barcode barcode;
    for (int i = 0; i < array.getSize(); i++) {
        if (array[i] == upc) {
            barcode = array[i];
        }
    }
    return barcode;
}
