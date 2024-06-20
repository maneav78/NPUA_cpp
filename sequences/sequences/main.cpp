#include <iostream>
#include "Sequence.h"
#include "GeopetricSequence.h"
#include <cmath>



int main() {
    int n;
    cout << "Give number of sequences: ";
    cin >> n;
    GeopetricSequence* arr = new GeopetricSequence[n];

    for (int i = 0; i < n; i++) {
        cout << "Give numbers of sequence " << i + 1 << ": ";
        cin >> arr[i];
    }
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].findTheMember(10) > arr[ind].findTheMember(10)) {
            ind = i;
        }
    }
    cout << "The sequence with the max 10th value is: " << endl;
    cout << arr[ind];

    delete[] arr;
    
    const int size = 3;

    Sequence* arr2[size];

    int m;
    cout << "Input count of numbers: ";
    cin >> m;

    for (int i = 0; i < size; i++) {
        cout << "Give numbers of sequence " << i + 1 << ": ";
        arr2[i] = new GeopetricSequence();
        cin >> *arr2[i];
    }

    int ind2 = 0;
    for (int i = 1; i < size; i++) {
        if (arr2[i]->findTheSum(m) > arr2[ind2]->findTheSum(m)) {
            ind2 = i;
        }
    }
    cout << "The sequence with max sum is: " << endl;
    cout << *arr2[ind2];
    
    for (int i = 0; i < size; i++) delete arr2[i];
    
    return 0;
}