#include "group7.h"
#include <random>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>



void generateRandomNumbers_NormalDistribution(int mean, int standard_deviation) {
    // Generate 20,000 random numbers with specified mean and standard deviation
	int numbers = 20000;
    int divider = 20;

    random_device rd{};
    mt19937 gen{rd()};
 
    // Values near the mean are the most likely.
    // Standard deviation affects the dispersion of generated values from the mean.
    normal_distribution<double> d{static_cast<double>(mean), static_cast<double>(standard_deviation)};
 
    // Draw a sample from the normal distribution and round it to an integer.
    auto random_int = [&d, &gen]{ return static_cast<int>(round(d(gen))); };
 
    // Map to store histogram counts.
    map<int, int> hist{};
    for (int n = 0; n != numbers; ++n)
        ++hist[random_int()];
 
    // Print histogram.
    printHistogram(hist, "$", divider);
}


void generateRandomNumbers_UniformDistribution(double min_value, double max_value) {
    //Check the min_value being less than max_value. 
    if(min_value > max_value){
        cout << "Error: Min Value should be less than Max Value." << endl;
        return; 
    }

	// Generate 20,000 random numbers with specified mean and standard deviation
	int numbers = 20000;
    int divider = 20;

	// Set up random number generator
    random_device rd;
    mt19937 gen(rd()); 

    // Create a uniform distribution object
    uniform_real_distribution<double> distribution(min_value, max_value);
 
    // Draw a sample from the normal distribution and round it to an integer.
    auto random_double = [&distribution, &gen]{ return static_cast<double>(distribution(gen)); };
 
    // Map to store histogram counts.
    map<int, double> hist{};
    for (int n = 0; n != numbers; ++n)
        ++hist[random_double()];
 
    // Print histogram.
    printHistogram(hist, "*", divider);
}


template<typename KeyType, typename ValueType>
void printHistogram(const map<KeyType, ValueType>& hist, const string& symbol, int divider) {

    //Using for to go through each key pair value in map. 
    for (const auto& [x, y] : hist) {
        cout << setw(2) << x << ' ';
        for (int i = 0; i < y / divider; ++i)
            cout << symbol;         //Printing the user specified symbol.
        cout << '\n';
    }
}


