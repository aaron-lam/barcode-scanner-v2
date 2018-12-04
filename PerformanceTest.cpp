/**
 * This file is for testing the performance of Array and Binary Search Tree
 * CS 300 Assignment 5
 * Professor Fatma Serce
 * @author: Aaron Lam
 * @date: 12-3-2018
 */

#include <iostream>
#include <limits>
#include <vector>

#include "BarcodeArrayScanner.h"
#include "BarcodeBSTScanner.h"
#include "BarcodeHashTableScanner.h"

using namespace std;

bool isNumber(string &s);

void testPerformance(BarcodeArrayScanner& arrayScanner, BarCodeBSTScanner& bstScanner, BarcodeHashTableScanner& hashTableScanner, vector<string>& list, int loopTimes);

int main(int argc, char** argv) {
    cout << "Loading file... Please wait." << endl;
    string fileName = "/Users/aaronlam/CLionProjects/BarcodeScanner/upc_corpus.txt";

    cout << "Now loading Array Scanner." << endl;
    BarcodeArrayScanner arrayScanner(fileName);
    cout << "Now loading BST Scanner." << endl;
    BarCodeBSTScanner bstScanner(fileName);
    cout << "Now loading Hash Table Scanner. (This will take around a minute)" << endl;
    BarcodeHashTableScanner hashTableScanner(fileName);


    cout << "Now loading vector for testing." << endl;
    vector<string> list;
    // read input file and saved upc numbers in vector for testing.
    ifstream infile(fileName);
    string upc;
    string info;
    while (getline(infile, info)) {
        upc = info.substr(0, info.find(','));
        if (!isNumber(upc)) {
            continue;
        }
        list.push_back(upc);
    }
    cout << "Finished loading.\n" << endl;
    // test the performance based on different number of looping times.
    for (int i = 100; i <= 1000; i += 100) {
        testPerformance(arrayScanner, bstScanner, hashTableScanner, list, i);
    }
}

/**
 * Print the time performance for both array and BST in certain looping times.
 */
void testPerformance(BarcodeArrayScanner& arrayScanner, BarCodeBSTScanner& bstScanner, BarcodeHashTableScanner& hashTableScanner, vector<string>& list, int loopTimes) {
    clock_t start_clock = clock();
    clock_t arrayTotalTime = start_clock;
    clock_t bstTotalTime = start_clock;
    clock_t hashTableTotalTime = start_clock;

    cout << "Now search " << loopTimes << " times:" << endl;
    for (int i = 0; i < loopTimes; i++) {
        string res = list.at(i);

        clock_t arrayTimer = clock();
        Barcode barcode = arrayScanner.find(res);
        arrayTimer = clock() - arrayTimer;

        clock_t bstTimer = clock();
        Barcode barcode2 = bstScanner.find(res);
        bstTimer = clock() - bstTimer;

        clock_t hashTableTimer = clock();
        Barcode barcode3 = hashTableScanner.find(res);
        hashTableTimer = clock() - hashTableTimer;

        arrayTotalTime += arrayTimer;
        bstTotalTime += bstTimer;
        hashTableTimer += hashTableTimer;
    }

    bstTotalTime -= start_clock;
    arrayTotalTime -= start_clock;
    hashTableTotalTime -= start_clock;

    cout << "Time taken of searching " << loopTimes << " times in BST:        " << bstTotalTime << " milliseconds" << endl;
    cout << "Time taken of searching " << loopTimes << " times in array:      " << arrayTotalTime  << " milliseconds" << endl;
    cout << "Time taken of searching " << loopTimes << " times in Hash Table: " << hashTableTotalTime << " milliseconds\n" << endl;
}

/**
 * @return true if the string can be converted to integer, else return false.
 */
bool isNumber(string &s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
