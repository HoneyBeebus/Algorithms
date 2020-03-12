//
//  yourid.cpp
//  
//
//  Created by Henry White on 12/03/2020.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void radixSort (vector<vector<int>> A, int k) {
    for (auto i = A.begin(); i != A.end(); i++) {
        auto r = upper_bound(A.begin(), i, *i);
        rotate(r, i, i + 1);
    }
    for (int i = 0; i < k; i++) {
           for (int j = 0; j < A[i].size(); j++) {
               cout << A[i][j] << ";";
           }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    int size;
    int temp;
    
    cin >> size;
    vector<vector<int>> A;
    for (int i = 0; i < size; i++) {
        vector<int> B;
        for (int j = 0; j < 10; j++) {
            cin >> temp;
            B.push_back(temp);
        }
        A.push_back(B);
    }
    int k = A.size();
    radixSort(A, k);
    
    A.clear();
    return 0;
}


