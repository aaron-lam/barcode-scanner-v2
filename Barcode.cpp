/**
 * This is the implementation file of Barcode class
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include "Barcode.h"

Barcode::Barcode() {}

Barcode::Barcode(const string &upc, const string &description) :
        upc(upc), description(description) {}

const string &Barcode::getUpc() const {
    return upc;
}

void Barcode::setUpc(const string &upc) {
    Barcode::upc = upc;
}

const string &Barcode::getDescription() const {
    return description;
}

void Barcode::setDescription(const string &description) {
    Barcode::description = description;
}

bool Barcode::operator<(const string &upc) const {
    return this->upc < upc;
}

bool Barcode::operator>(const string &upc) const {
    return this->upc > upc;
}

bool Barcode::operator<(const Barcode &rhs) const {
    return upc < rhs.upc;
}

bool Barcode::operator==(const string &otherUpc) const {
    return upc == otherUpc;
}
