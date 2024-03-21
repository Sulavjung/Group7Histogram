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