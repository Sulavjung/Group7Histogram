Group #: 7
Students: 1. Sulav Jung Hamal 2. Alex Corona 3. Michael McGruder 4. Zachary Leyden (No Contribution)

---

### 1: Histogram of Random Numbers with Normal Distribution

#### Input:

- `mean`: Mean value of the normal distribution.
- `standard_deviation`: Standard deviation of the normal distribution.

#### Output:

- Print a histogram showing the distribution of the generated random numbers.

#### Algorithm:

1. Generate 20,000 random numbers using a normal distribution with mean and standard deviation specified.
2. Create a map to store histogram counts.
3. Draw a sample from the normal distribution and round it to an integer.
4. Increment the count for the corresponding histogram bin.
5. Print the histogram using the `printHistogram` function.

#### Pseudo Code:

```
generateRandomNumbers_NormalDistribution(mean, standard_deviation):
    Generate 20,000 random numbers using normal distribution with mean and standard deviation
    Create an empty map 'hist' to store histogram counts
    for n from 0 to 19,999:
        Generate a random number 'num' from the normal distribution
        Increment hist[num] by 1
    Print histogram using printHistogram(hist, "$", divider)
```

#### Worst-Case Time Complexity Analysis:

- Generating 20,000 random numbers using the normal distribution takes O(1) time per number.
- Inserting each number into the map takes O(log N) time, where N is the number of unique values generated.
- Printing the histogram takes O(N) time, where N is the number of unique values generated.

#### Data Structures:

- Map (std::map) is used to store histogram counts because it provides an efficient way to count occurrences of each value.

---

### 2: Generating Histogram for Random Numbers with Uniform Distribution

#### Input:

- `min_value`: Minimum value of the uniform distribution.
- `max_value`: Maximum value of the uniform distribution.

#### Output:

- Print a histogram showing the distribution of the generated random numbers.

#### Algorithm:

1. Generate 20,000 random numbers using a uniform distribution between min_value and max_value.
2. Create a map to store histogram counts.
3. Draw a sample from the uniform distribution.
4. Increment the count for the corresponding histogram bin.
5. Print the histogram using the `printHistogram` function.

#### Pseudo Code:

```
generateRandomNumbers_UniformDistribution(min_value, max_value):
    Generate 20,000 random numbers using uniform distribution between min_value and max_value
    Create an empty map 'hist' to store histogram counts
    for n from 0 to 19,999:
        Generate a random number 'num' from the uniform distribution
        Increment hist[num] by 1
    Print histogram using printHistogram(hist, "*", divider)
```

#### Worst-Case Time Complexity Analysis:

- Generating 20,000 random numbers using the uniform distribution takes O(1) time per number.
- Inserting each number into the map takes O(log N) time, where N is the number of unique values generated.
- Printing the histogram takes O(N) time, where N is the number of unique values generated.

#### Data Structures:

- Map (std::map) is used to store histogram counts because it provides an efficient way to count occurrences of each value.

---

### 3: Implementation of Randomized QuickSort Algorithm

#### Input:

- `arr`: Vector of elements to be sorted.
- `low`: Index of the lowest element in the range to be sorted.
- `high`: Index of the highest element in the range to be sorted.
- `comp`: Comparator function to define the order of elements.

#### Output:

- The input array `arr` is sorted in non-decreasing order based on the comparator function `comp`.

#### Algorithm:

1. User inputted array with values of string and int
2. Prints current array in current order
3. Array gets partitioned
4. Array gets sorted by non-decreasing order based on frequency
5. Checked for any mistakes
6. Prints new current array in non-decreasing order

#### Pseudo Code:

```cpp
randomizedQuickSort(arr, low, high, comp):
    if low < high:
        // Partition the array
        pi = partition(arr, low, high, comp)

        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pi - 1, comp)
        randomizedQuickSort(arr, pi + 1, high, comp)

partition(arr, low, high, comp):
    // Randomly select a pivot element
    randomIndex = randomly select an index between low and high
    swap arr[randomIndex] with arr[high]
    pivot = arr[high]

    // Initialize index of smaller element
    i = low - 1

    // Partitioning loop
    for j from low to high - 1:
        // If current element is smaller than or equal to pivot
        if comp(arr[j], pivot):
            // Increment index of smaller element
            i++
            // Swap arr[i] with arr[j]
            swap arr[i] with arr[j]

    // Swap arr[i + 1] with arr[high] (to place pivot in correct position)
    swap arr[i + 1] with arr[high]
    // Return the index of pivot element
    return i + 1


```

#### Worst-Case Time Complexity Analysis:

1. Average Case: O(n\*log(n))
2. Worst Case: O(n^2)
3. Best Case: O(n\*log(n))

The worst-case time complexity of the Randomized QuickSort algorithm is O(n^2). This occurs when the partition function consistently selects the smallest or largest element as the pivot, resulting in unbalanced partitions. However, in practice, the expected time complexity is O(n log n) on average, as the pivot selection is randomized.

---

### 4: Finding the k-th Smallest Element in an Array (Randomized Version)

#### Input:

- `k`: The rank of the element to find (e.g., the k-th smallest element).
- `arr`: The array of elements in which to find the k-th smallest element.
- `first`: The index of the first element in the array.
- `last`: The index of the last element in the array.
- `comp`: A function object or lambda representing the comparison criteria.

#### Output:

- Returns the k-th smallest element in the array.

#### Algorithm:

1. Check if there is only one element in the partition, in which case return it as the k-th smallest.
2. Partition the array around a pivot element chosen randomly.
3. Calculate the length of the left partition.
4. If k equals the length of the left partition, return the pivot element as the k-th smallest.
5. If k is less than the length, recursively search in the left partition.
6. If k is greater than the length, recursively search in the right partition.

#### Pseudo Code:

```
kSmall(k, arr, first, last, comp):
    if first == last:
        return arr[first]
    pivotIndex = partition(arr, first, last, comp)
    length = pivotIndex - first + 1
    if k == length:
        return arr[pivotIndex]
    else if k < length:
        return kSmall(k, arr, first, pivotIndex - 1, comp)
    else:
        return kSmall(k - length, arr, pivotIndex + 1, last, comp)
```

#### Worst-Case Time Complexity Analysis:

- The partitioning step takes O(N) time, where N is the number of elements in the partition.
- Each recursive call reduces the problem size by approximately half.
- Overall time complexity is O(N) on average and O(N^2) in the worst case.

---

### Common Functions:

#### `printHistogram` Function

#### Input:

- `hist`: Map containing histogram counts.
- `symbol`: Symbol used to represent each unit in the histogram.
- `divider`: Value used to scale down the frequency of histogram counts.

#### Output:

- Print a histogram showing the distribution of the data.

#### Algorithm:

1. Iterate through the map and print the histogram using the specified symbol and divider.

#### Pseudo Code:

```
printHistogram(hist, symbol, divider):
    for each key-value pair (x, y) in hist:
        Print x followed by a space
        Print y divided by divider number of times using the specified symbol
        Print a newline character
```

#### Worst-Case Time Complexity Analysis:

- Printing the histogram takes O(N) time, where N is the number of unique values in the map.

---

---

### File: `group7.h`

```cpp
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

```

---

### File: `quickSort.cpp`

```cpp
#include <random>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;


//Problem 3:
// Function template for partitioning
template<typename T, typename Compare>
int partition(vector<T>& arr, int low, int high, Compare comp) {
    // Randomly choose a pivot element
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(low, high);
    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[high]);
    T pivot = arr[high];

    int i = low - 1;

    // Partitioning loop
    for (int j = low; j < high; j++) {
        if (comp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function template for QuickSort
template<typename T, typename Compare>
void randomizedQuickSort(vector<T>& arr, int low, int high, Compare comp) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high, comp);

        // Recursively sort elements before and after partition
        randomizedQuickSort(arr, low, pi - 1, comp);
        randomizedQuickSort(arr, pi + 1, high, comp);
    }
}

// Function template for finding k-th smallest item
template<typename T, typename Compare>
T kSmall(int k, std::vector<T>& arr, int first, int last, Compare comp) {
    // If only one element in the partition, return it as the k-th smallest
    if (first == last) return arr[first];

    // Partition the array around a pivot element
    int pivotIndex = partition(arr, first, last, comp);

    // Calculate the length of the left partition
    int length = pivotIndex - first + 1;
    if (k == length) {
        // If k equals the length of the left partition, the pivot is the k-th smallest
        return arr[pivotIndex];
    } else if (k < length) {
        //Recursively search in the left partition
        return kSmall(k, arr, first, pivotIndex - 1, comp);
    } else {
        // Recursively search in the right partition
        return kSmall(k - length, arr, pivotIndex + 1, last, comp);
    }
}
```

---

### File: `group7.cpp`

```cpp
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

```

---

### File: `tests.h`

```cpp
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

```

---

### File: `main.cpp`

```cpp
#include "tests.h"
#include <iostream>

using namespace std;

int main() {

    /*
	Testing Histogram Generation of Normally Distributed Random Numbers
    */
    generateRandomNumbers_NormalDistribution_test1();
    cout << endl;
    generateRandomNumbers_NormalDistribution_test2();
     cout << endl;


    /*
	Testing Histogram Generation of Normally Distributed Random Numbers
    */
    generateRandomNumbers_UniformDistribution_test1();
     cout << endl;
    generateRandomNumbers_UniformDistribution_test2();
     cout << endl;
    generateRandomNumbers_UniformDistribution_test3();


    /*
	Testing Randomized quick sort with user defined criterion.
    */
    quickSort_Test1();
    quickSort_Test2();
    quickSort_Test3();

    /*
	Testing Randomized kSmall that finds the kth ranked object in an array.
    */
    cout << endl <<  "*************************************************" << endl;
    cout << "Randomized kSmall that finds the kth ranked object in an array." << endl;
    kSmall_Test1();
    kSmall_Test2();
    kSmall_Test3();

    return 0;
}

```

---

### File: Makefile

```Makefile
run_all:
	g++ -std=c++17 *.cpp -o app
	./app
```
