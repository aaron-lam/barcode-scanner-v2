/**
 * This is the header file of Barcode Array Scanner
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef BARCODE_ARRAY_SCANNER_H
#define BARCODE_ARRAY_SCANNER_H

#include <fstream>
#include <sstream>

#include "Array.cpp"
#include "Barcode.h"
#include "string"

class BarcodeArrayScanner {
public:
    BarcodeArrayScanner(const string& fileName);

    Barcode find(const string& upc);
private:
    Array<Barcode> array;
};


#endif
