#include <iostream>
using namespace std;
#include "..\..\include\MArray.h"

void test_array(Array<int> &A) {
    cout << "Current array: ";
    for (size_t i = 0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;
    Array<int>::Marker mar(A.begin());
    Array<int>::Marker mar1(A.end()); --mar1;
    //A.erase(1);
    cout << "1st marker: " << mar.get_data() << " and 2nd: " << *mar1 << endl;
    cout << "Increment 1st & erase: "; ++mar; A.erase(mar);
    
    for (size_t i = 0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;

    Array<int>::Marker start(A.begin());
    Array<int>::Marker stop(A.end()); stop--;
    cout << ((search(start, stop, 14) != stop) ? "14 is here" : "14 is out") << endl;
}

int main() {
    cout << "Hello, World!" << endl;
    Array<int> A = Array<int>();
    A.push_back(3);
    A.push_back(14);
    A.push_back(15);
    A.push_back(92);
    A.push_back(65);

    test_array(A);

    cout << endl;
    cout << "Test exited." << endl;

    return 0;
}