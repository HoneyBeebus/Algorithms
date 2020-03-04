//
//  yourid.cpp
//  
//
//  Created by Henry White on 04/03/2020.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

//Function that partitions array given a pivot point
int partition(int * A, int p, int r) {
    int x, i;
    x = A[r];
    i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return (i + 1);
}

//Function that generates a random number given a range of elements
int random(int a, int b) {
    int c;
    srand(time(NULL));
    c =  a + rand() % (b - a);
    return (c);
}

//Function to partiton based on a random pivot point
int randomizedPartition(int * A, int p, int r) {
    int i;
    i = random(p, r);
    swap(A[i], A[r]);
    return (partition(A, p, r));
    
}

//Randomized Quicksort implemented using CLRS 3rd edition psuedo-code
void randomizedQuicksort(int * A, int p, int r) {
    if (p < r) {
        int q;
        q = randomizedPartition(A, p, r);
        randomizedQuicksort(A, p, q - 1);
        randomizedQuicksort(A, q + 1, r);
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
    
    randomizedQuicksort(Sequence, 0, size - 1);
    
    for (int i = 0; i < size; i++) {
        cout << Sequence[i] << ";";
    }
    
    delete[] Sequence;
    
    
}
