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
