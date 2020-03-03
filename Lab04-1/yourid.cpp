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

int parent(int i) {
    int temp;
    temp = floor(i/2);
    return (temp);
}

int left(int i) {
    int temp;
    temp = 2*i;
    return (temp);
}

int right(int i) {
    return ((2*i) + 1);
}

int heapMaximum(int * A) {
    int temp;
    temp = A[i];
    return (temp);
}

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

void maxHeapInsert(int * A, int heapSize, int key) {
    heapSize--;
    A[heapSize] = -2147483647;
    heapIncreaseKey(A, heapSize, key);
}

void maxHeapify(int * A, int i, int heapSize) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l <= heapSize && A[l] > A[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r <= heapSize && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(int * A, int length) {
    int heapSize;
    heapSize = length;
    for (int i = floor(length / 2); i >= 1; i--) {
        maxHeapify(A, i, heapSize);
    }
}

int heapExtractMax(int * A, int heapSize) {
    int max;
    if (heapSize < 1) {
        cout << "heap underflow";
        return 0;
    }
    max = A[1];
    A[1] = A[heapSize];
    heapSize--;
    maxHeapify(A, 1, heapSize);
    return max;
    
}

void heapsort(int * A, int length) {
    buildMaxHeap(A, length);
    int heapSize;
    heapSize = length;
    for (int i = length; i <= 2; i--) {
        int temp;
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        heapSize--;
        maxHeapify(A, 1, heapSize);
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
    
    for (int i = 0; i < size; i++) {
        cout << Sequence[i] << ";";
    }
    
    delete[] Sequence;
    
    
}
