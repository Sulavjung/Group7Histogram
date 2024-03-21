#ifndef GROUP7_H
#define GROUP7_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;


//Problem 3
// Define a struct for TokenFreq
struct TokenFreq {
    string token;
    int frequency;

    // Constructor
    TokenFreq(string t, int f) : token(t), frequency(f) {}

    // Overloading < operator for sorting
    bool operator<(const TokenFreq& other) const {
        // Sort based on frequency in descending order
        return frequency > other.frequency;
    }

    // Print function for TokenFreq
    void print() const {
        cout << "  " << "Token: " << token << ", Frequency: " << frequency << endl;
    }
};


// Function prototypes
void generateRandomNumbers_NormalDistribution(int mean, int standard_deviation);

void generateRandomNumbers_UniformDistribution(double min_value, double max_value);

// Template for printHistogram function
template<typename KeyType, typename ValueType>
void printHistogram(const map<KeyType, ValueType>& hist, const string& symbol, int divider);

#include "quickSort.cpp"
#endif
