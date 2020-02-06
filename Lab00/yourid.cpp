//
//  cwhite24.cpp
//
//
//  Created by Henry White on 29/01/2020.
//
#include <iostream>
#include <algorithm>

#define MAX_INT 2147483647

using namespace std;


//Insertion Sort implementation from Cormen, Leiserson, Rivest, and Stein, 3rd Edition

void Insertion_Sort(int A[], int size) {
    //Initialize Variables
    int key;
    int i;
    
    for (int j = 1; j < size; j ++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}


int main(int argc, char **argv) {
    
    //Initialize Variables
    int* Sequence;
    int size;
    
    //Read size of array and create an array of that size
    cin >> size;
    Sequence = new int[size];
    
    //Read individual values for the sequence
    for (int i = 0; i < size; i++) {
        cin >> Sequence[i];
    }
    
    //Sort Array using Insertion Sort
    Insertion_Sort(Sequence, size);
    
    //Output
    cout << Sequence[size - 1] << ";" << Sequence[0];
    
    //Free allocated space
    delete[] Sequence;
    
}
