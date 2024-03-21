#ifndef TEST_H
#define TEST_H

#include "group7.h"
#include <iostream>
#include <cassert>


/*
	Testing Histogram Generation of Normally Distributed Random Numbers
*/
void generateRandomNumbers_NormalDistribution_test1() {
    // Test case for generateRandomNumbers_NormalDistribution - Normal case
    std::cout << "Testing generateRandomNumbers_NormalDistribution_test1 (Normal case)\n";
    generateRandomNumbers_NormalDistribution(0, 10);
}

void generateRandomNumbers_NormalDistribution_test2() {
    // Test case for generateRandomNumbers_NormalDistribution - Edge case
    std::cout << "Testing generateRandomNumbers_NormalDistribution_test2 (Edge case)\n";
    generateRandomNumbers_NormalDistribution(100, 0);
}


/*
	Testing Histogram Generation of Uniformly Distributed Random Numbers
*/
void generateRandomNumbers_UniformDistribution_test1() {
    // Test case for generateRandomNumbers_UniformDistribution - Normal case
    std::cout << "Testing generateRandomNumbers_UniformDistribution_test1 (Normal case)\n";
    generateRandomNumbers_UniformDistribution(0, 10);
}

void generateRandomNumbers_UniformDistribution_test2() {
    // Test case for generateRandomNumbers_UniformDistribution - Edge case
    std::cout << "Testing generateRandomNumbers_UniformDistribution_test2 (Edge case)\n";
    generateRandomNumbers_UniformDistribution(10, 10);
}

void generateRandomNumbers_UniformDistribution_test3() {
    // Test case for generateRandomNumbers_UniformDistribution - Edge case
    std::cout << "Testing generateRandomNumbers_UniformDistribution_test3 (Edge case)\n";
    generateRandomNumbers_UniformDistribution(10, 1);
}

/*
	Testing Randomized quick sort with user defined criterion. 
*/
void quickSort_Test1() {
    try {
        // Test case 1: Sorting by frequency in ascending order
        vector<TokenFreq> tokens = {
            {"apple", 5},
            {"banana", 10},
            {"orange", 3},
            {"grape", 8},
            {"pear", 6}
        };

        cout << endl << "*************************************************" << endl;
        cout << "Randomized Quick Sort Test 1: Sorting by frequency in ascending order" << endl;

        cout << endl << "Before sorting:" << endl;
        cout << "Tokens:" << endl;
        for (const auto& token : tokens) {
            token.print();

        }
        cout << endl;


        randomizedQuickSort(tokens, 0, tokens.size() - 1, less<TokenFreq>());


        cout << endl << "After sorting:" << endl;
        cout << "Tokens:" << endl;
        for (const auto& token : tokens) {
            token.print();  
        }
        cout << endl;


        // Check if sorted correctly
        if (tokens[0].frequency == 10 &&
            tokens[1].frequency == 8 &&
            tokens[2].frequency == 6 &&
            tokens[3].frequency == 5 &&
            tokens[4].frequency == 3) {
            cout << "quickSort_Test1 passed\n" << endl;
        } else {
            cout << "quickSort_Test1 failed\n" << endl;
        }
    } catch (const exception& e) {
        cout << "quickSort_Test1 failed: " << e.what() << endl;
    }
}

void quickSort_Test2() {
    try {
        // Test case 2: Sorting by token in ascending order
        vector<TokenFreq> tokens = {
            {"pear", 6},
            {"banana", 10},
            {"grape", 8},
            {"orange", 3},
            {"apple", 5}
        };

        cout << endl << "*************************************************" << endl;
        cout << "Randomized Quick Sort Test 2: Sorting by token in ascending order" << endl;

        cout << endl << "Before sorting:" << endl;
        cout << "Tokens:" << endl;
        for (const auto& token : tokens) {
            token.print();

        }
        cout << endl;

        randomizedQuickSort(tokens, 0, tokens.size() - 1, [](const TokenFreq& a, const TokenFreq& b) {
            return a.token < b.token;
        });

        cout << endl << "After sorting:" << endl;
        cout << "Tokens:" << endl;
        for (const auto& token : tokens) {
            token.print();

        }
        cout << endl;

        // Check if sorted correctly
        if (tokens[0].token == "apple" &&
            tokens[1].token == "banana" &&
            tokens[2].token == "grape" &&
            tokens[3].token == "orange" &&
            tokens[4].token == "pear") {
            cout << "quickSort_Test2 passed\n";
        } else {
            cout << "quickSort_Test2 failed\n";
        }
    } catch (const exception& e) {
        cout << "quickSort_Test2 failed: " << e.what() << endl;
    }
}


void quickSort_Test3() {
    try {
        // Test case 3: Sorting empty vector
        vector<TokenFreq> tokens;
        cout << endl <<  "*************************************************" << endl;
        cout << "Randomized Quick Sort Test 3: Sorting empty vector" << endl;

        randomizedQuickSort(tokens, 0, tokens.size() - 1, less<TokenFreq>());

        // Check if sorted correctly (should have no effect on empty vector)
        if (tokens.empty()) {
            cout << "quickSort_Test3 passed\n";
        } else {
            cout << "quickSort_Test3 failed\n";
        }
    } catch (const exception& e) {
        cout << "quickSort_Test3 failed: " << e.what() << endl;
    }
}


/*
Testing Randomized kSmall that finds the kth ranked object in an array. 
*/
void kSmall_Test1() {
    // Test case 1
    vector<int> arr1 = {3, 1, 4, 1, 5};
    int k1 = 2; // Find the 2nd smallest item
    int kthSmallest1 = kSmall(k1 - 1, arr1, 0, arr1.size() - 1, less<int>());
    if (kthSmallest1 == 1) {
        cout << "kSmall_Test1 passed\n";
    } else {
        cout << "kSmall_Test1 failed: Expected 1, but got " << kthSmallest1 << "\n";
    }
}

void kSmall_Test2() {
    // Test case 2
    vector<int> arr2 = {5, 2, 9, 1, 7};
    int k2 = 3; // Find the 3rd smallest item
    int kthSmallest2 = kSmall(k2 - 1, arr2, 0, arr2.size() - 1, less<int>());
    if (kthSmallest2 == 2) {
        cout << "kSmall_Test2 passed\n";
    } else {
        cout << "kSmall_Test2 failed: Expected 2, but got " << kthSmallest2 << "\n";
    }
}

void kSmall_Test3() {
    // Test case 3 (Edge case: array with one element)
    vector<int> arr3 = {10};
    int k3 = 1; // Find the 1st smallest item
    int kthSmallest3 = kSmall(k3 - 1, arr3, 0, arr3.size() - 1, less<int>());
    if (kthSmallest3 == 10) {
        cout << "kSmall_Test3 passed\n";
    } else {
        cout << "kSmall_Test3 failed: Expected 10, but got " << kthSmallest3 << "\n";
    }
}


#endif
