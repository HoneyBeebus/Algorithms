//
//  yourid.cpp
//  
//
//  Created by Henry White on 13/02/2020.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

//Function used to identify parent node
int parent(int i) {
    int temp;
    temp = floor(i/2);
    return (temp);
}

//Funciton used to identify left child
int left(int i) {
    int temp;
    temp = 2*i + 1;
    return (temp);
}

//Function used to identify right child
int right(int i) {
    return ((2*i) + 2);
}

//Function used to find maximum value
int heapMaximum(int * A) {
    int temp;
    temp = A[1];
    return (temp);
}

//Function used to increase the key of a node
void heapIncreaseKey(int * A, int i, int key) {
    if (key < A[i]) {
        cout << "new key is smaller than current key";
        return;
    }
    A[i] = key;
    while (i > 1 && A[parent(i)] < A[i]) {
        int temp;
        temp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = temp;
        i = parent(i);
    }
}

//Function that allows inseriton into the max heap
void maxHeapInsert(int * A, int heapSize, int key) {
    heapSize--;
    A[heapSize] = -2147483647;
    heapIncreaseKey(A, heapSize, key);
}

//Function that maintains heap and ensures it doesn't violate propertires of a heap
void maxHeapify(int * A, int i, int heapSize) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heapSize && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r < heapSize && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        maxHeapify(A, largest, heapSize);
    }
}

//Function to construct a heap given an array
void buildMaxHeap(int * A, int length) {
    int heapSize;
    heapSize = length;
    for (int i = floor(length / 2); i >= 0; i--) {
        maxHeapify(A, i, heapSize);
    }
}

//Funciton to return the max of a heap that is not a max or min heap
int heapExtractMax(int * A, int heapSize) {
    int max;
    if (heapSize < 1) {
        cout << "heap underflow";
        return 0;
    }
    max = A[0];
    A[0] = A[heapSize];
    heapSize--;
    maxHeapify(A, 0, heapSize);
    return max;
    
}

//Implementation of heapsort adhering to CLRS 3rd Edition
void heapsort(int * A, int length) {
    buildMaxHeap(A, length);
    for (int i = length - 1; i >= 0; i--) {
        int temp;
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A, 0, i);
    }
}

//driver function
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
    
    heapsort(Sequence, size);
    
    for (int i = 0; i < size; i++) {
        cout << Sequence[i] << ";";
    }
    
    delete[] Sequence;
    
    
}
