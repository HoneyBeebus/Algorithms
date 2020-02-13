//
//  cwhite24.cpp
//  
//
//  Created by Henry White on 05/02/2020.
//
#include <iostream>
#include <stdio.h>
#include <cmath>

#define MAX_INT 2147483647

using namespace std;

//Function for handling output
void Output(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << ";";
    }
}

//Merge implementation from Cormen, Leiserson, Rivest, and Stein, 3rd Edition and Geeks for Geeks
void merge(int A[], int p, int q, int r) {
//  Initialize Variables
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L;
    int* R;
    
    L = new int[n1];
    R = new int[n2];

//  Populate Arrays with Left and Right indicies
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    
//  Could not get the sentinel values to work. However, sorting still works and tests are passed.
//  L[n1] = MAX_INT;
//  R[n2] = MAX_INT;
    
    int i = 0;
    int j = 0;
    int k = p;
    
//  Merging of left and right subarrays
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

//  Cleanup for indicies that don't get merged from above while statement
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

//  Clearing up memory
    delete[] L;
    delete[] R;
}

//Merge Sort implementation from Cormen, Leiserson, Rivest, and Stein, 3rd Edition
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = floor((p + r)/2);
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}


//Driver function
int main(int argc, char **argv) {
//  Initialize Variables
    int size;
    int *Sequence;

//  Create sequence of input size
    cin >> size;
    Sequence = new int[size];

//  Read elements of sequence
    for(int i = 0; i < size; i++) {
        cin >> Sequence[i];
    }

//  Function calls
    mergeSort(Sequence, 0, size - 1);

    Output(Sequence, size);
    
//  Clean memory
    delete[] Sequence;
}

