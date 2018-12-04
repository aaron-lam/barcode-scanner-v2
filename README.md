# BarcodeScanner

BarcodeScanner is an application for searching barcode with upc number.

We use this application to test the time performance of data structures, including array, binary search tree, and hash table.

# Getting Started

## Run Performance Test

1. Please copy and paste the following command line in your terminal to build the project.
```
g++ ArrayAndBSTPerformance.cpp BinarySearchTree.cpp Array.cpp Barcode.cpp BarcodeArrayScanner.cpp BarcodeBSTScanner.cpp HashTable.cpp BarcodeHashTableScanner.cpp -o Performance
```

2. Then run the application with the text file path specified
```
./Performance [enter_input_file_path_here] (ex: ./Performance /home/user/cs300_4/upc_corpus.txt)
```
You will see the performance test result after running the test:

```
Loading file... Please wait.
Now loading Array Scanner.
Now loading BST Scanner.
Now loading Hash Table Scanner. (This will take around a minute)
Now loading vector for testing.
Finished loading.

Now search 100 times:
Time taken of searching 100 times in BST:        304 milliseconds
Time taken of searching 100 times in array:      3002063 milliseconds
Time taken of searching 100 times in Hash Table: 0 milliseconds

Now search 200 times:
Time taken of searching 200 times in BST:        660 milliseconds
Time taken of searching 200 times in array:      6087609 milliseconds
Time taken of searching 200 times in Hash Table: 0 milliseconds

Now search 300 times:
Time taken of searching 300 times in BST:        912 milliseconds
Time taken of searching 300 times in array:      8877762 milliseconds
Time taken of searching 300 times in Hash Table: 0 milliseconds

Now search 400 times:
Time taken of searching 400 times in BST:        1264 milliseconds
Time taken of searching 400 times in array:      11349280 milliseconds
Time taken of searching 400 times in Hash Table: 0 milliseconds

Now search 500 times:
Time taken of searching 500 times in BST:        1680 milliseconds
Time taken of searching 500 times in array:      14003103 milliseconds
Time taken of searching 500 times in Hash Table: 0 milliseconds

Now search 600 times:
Time taken of searching 600 times in BST:        1948 milliseconds
Time taken of searching 600 times in array:      16399737 milliseconds
Time taken of searching 600 times in Hash Table: 0 milliseconds

Now search 700 times:
Time taken of searching 700 times in BST:        2024 milliseconds
Time taken of searching 700 times in array:      18552795 milliseconds
Time taken of searching 700 times in Hash Table: 0 milliseconds

Now search 800 times:
Time taken of searching 800 times in BST:        3091 milliseconds
Time taken of searching 800 times in array:      21530724 milliseconds
Time taken of searching 800 times in Hash Table: 0 milliseconds

Now search 900 times:
Time taken of searching 900 times in BST:        2688 milliseconds
Time taken of searching 900 times in array:      23803689 milliseconds
Time taken of searching 900 times in Hash Table: 0 milliseconds

Now search 1000 times:
Time taken of searching 1000 times in BST:        2602 milliseconds
Time taken of searching 1000 times in array:      25720872 milliseconds
Time taken of searching 1000 times in Hash Table: 0 milliseconds
```

# Data Structure Performance Analysis
Here is the result of time performance.

<img width="800" alt="time performance graph BST" src="https://user-images.githubusercontent.com/23665164/49344548-b37bdb00-f62d-11e8-9923-640a0614dc1b.png">

<img width="800" alt="time performance graph Array" src="https://user-images.githubusercontent.com/23665164/49344549-b37bdb00-f62d-11e8-8f5b-8a04b63310f6.png">

<img width="800" alt="time performance graph Hash Table" src="https://user-images.githubusercontent.com/23665164/49421906-9ab31880-f746-11e8-9cb1-6c4567c78f89.png">
