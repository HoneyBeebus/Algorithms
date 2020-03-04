//
//  yourid.cpp
//  
//
//  Created by Henry White on 11/02/2020.
//
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

//  Sturcture used to hold outputs of functions
struct Container {
    int low;
    int high;
    int sum;
};

//  Implementation of Find-Max-Crossing-Subarray from Introduction to Algorithms - 3rd Edition CLRS
Container findMaxCrossingSubarray (int *A, int low, int mid, int high) {
    
//  Initialize Variables
    Container out;
//  Set left sum to -2147483647 which is the smallest INT possible
    int leftSum = -2147483647;
    int sum = 0;
    int maxLeft = 0;
    int maxRight = 0;
    
    for (int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
//  Set right sum to -2147483647 which is the smallest INT possible
    int rightSum = -2147483647;
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    out.low = maxLeft;
    out.high = maxRight;
    out.sum = leftSum + rightSum;
    
    return out;
}

//  Implementation of Find-Maximum-Subarray from Introduction to Algorithms - 3rd Edition CLRS
Container findMaximumSubarray( int *A, int low, int high) {
//  Base case when array is only one element
    if (high == low) {
        Container baseCase;
        baseCase.low = low;
        baseCase.high = high;
        baseCase.sum = A[low];
        return baseCase;
    }
    else {
        int mid = floor((low + high) / 2);
        Container Left;
        Container Right;
        Container Cross;
        Left = findMaximumSubarray(A, low, mid);
        Right = findMaximumSubarray(A, mid + 1, high);
        Cross = findMaxCrossingSubarray(A, low, mid, high);
        if (Left.sum >= Right.sum && Left.sum >= Cross.sum) {
            return Left;
        }
        else if (Right.sum >= Left.sum && Right.sum >= Cross.sum) {
            return Right;
        }
        else {
            return Cross;
        }
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
    Container Solution;
    Solution = findMaximumSubarray(Sequence, 0, size - 1);

//  Output
    cout << Solution.sum;
    
//  Clean memory
    delete[] Sequence;
    return 0;
}
