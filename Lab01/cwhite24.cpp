//
//  cwhite24.cpp
//
//
//  Created by Henry White on 29/01/2020.
//
#include <iostream>

using namespace std;

//Function to handle output for specifications of lab
void Output_Handler(int A[], int iteration) {
    for (int i = 0; i < iteration; i++) {
        cout << A[i] << ";";
    }
    cout << endl;
}

//Insertion Sort implementation from Cormen, Leiserson, Rivest, and Stein, 3rd Edition
void Insertion_Sort(int A[], int size) {
    //Initialize Variables
    int key;
    int i;
    int iteration = 1;
        
    for (int j = 1; j < size; j ++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
        iteration++;
        Output_Handler(A, iteration);
    }
}

int main(int argc, char **argv) {
    //Initialize Variables
    int size;
    int *Sequence;
    
    //Create sequence of input size
    cin >> size;
    Sequence = new int[size];
    
    //Read elements of sequence
    for(int i = 0; i < size; i++) {
        cin >> Sequence[i];
    }
    
    Insertion_Sort(Sequence, size);
    
    delete[] Sequence;
    
    
}
