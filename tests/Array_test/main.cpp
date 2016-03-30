#include <iostream>
using namespace std;
#include "..\..\include\MArray.h"

void test_array(Array<int> &A) {
    cout << "Current array: ";
    for (size_t i = 0; i < A.size(); i++) cout << A[i] << " ";
    cout << endl;
    Array<int>::Marker mar(A);
    //A.del(1);
    cout << "Will set marker to: " << mar.get_data() << endl;
    cout << "Now increment marker: "; ++mar;
    cout << *mar << endl; // can use * like pointers
    cout << "Now erase marked: ";
    A.erase(mar);
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

    for (size_t i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    cout << ((A.search(15) != A.end()) ? "15 is in array" : "no 15") << endl;
    cout << ((A.search(99) != A.end()) ? "99 is in array" : "no 99") << endl;

     return 0;
}