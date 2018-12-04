/**
 * This is the header file of Barcode class
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#ifndef BARCODE_H
#define BARCODE_H

#include <iostream>
#include <string>

using namespace std;

class Barcode {
public:
    Barcode();

    Barcode(const string &upc, const string &description);

    const string &getUpc() const;

    void setUpc(const string &upc);

    const string &getDescription() const;

    void setDescription(const string &description);

    bool operator<(const Barcode &rhs) const;

    bool operator<(const string &upc) const;

    bool operator>(const string &upc) const;

    bool operator==(const string &otherUpc) const;

private:
    string upc;
    string description;
};


#endif
