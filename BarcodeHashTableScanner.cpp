/**
 * This is the implementation file of the barcode Hash Table Scanner.
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include "BarcodeHashTableScanner.h"

/**
 * Constructor.
 */
BarcodeHashTableScanner::BarcodeHashTableScanner(const string &fileName) {
    ifstream infile(fileName);
    string upc, description;
    string info;
    while (getline(infile, info)) {
        upc = info.substr(0, info.find(','));
        if (!isNumber(upc)) {
            continue;
        }
        description = info.substr(info.find(',') + 1);
        Barcode barcode(upc, description);
        table.insert(upc, barcode);
    }
}

/**
 * Return the corresponding barcode with the upc number
 */
Barcode BarcodeHashTableScanner::find(const string &upc) {
    return table.find(upc);
}

/**
 * @return true if the string can be converted to integer, else return false.
 */
bool BarcodeHashTableScanner::isNumber(string &s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
