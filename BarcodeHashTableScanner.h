/**
 * This is the header file of the barcode Hash Table Scanner.
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef BARCODE_HASH_TABLE_SCANNER_H
#define BARCODE_HASH_TABLE_SCANNER_H

#include <fstream>

#include "Barcode.h"
#include "HashTable.cpp"

class BarcodeHashTableScanner {
    public:
        BarcodeHashTableScanner(const string& fileName);

        Barcode find(const string& upc);
    private:
        HashTable<string, Barcode> table;

    bool isNumber(string &s);
};


#endif
