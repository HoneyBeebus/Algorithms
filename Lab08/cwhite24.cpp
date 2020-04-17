//
//  yourid.cpp
//  
//
//  Created by Henry White on 15/04/2020.
//

#include <iostream>
#include <stdio.h>

using namespace std;

void printOptimalParens(int *s, int i, int j, int n) {
    if (i == j) {
        cout << "A" << i - 1;
        return;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, *((s+i*n)+j), n);
        printOptimalParens(s,*((s+i*n)+j)+1, j, n);
        cout << ")";
    }
}

int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[n][n];
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 2147483647;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n-1] << endl;
    printOptimalParens((int *)s, 1, n-1, n);
    cout << endl;
    return m[1][n-1];
}

int main (int argc, char ** argv) {
    int size;
    cin >> size;
    int *p;
    p = new int[size];

    for (int i = 0; i <= size; i++) {
        cin >> p[i];
    }
    matrixChainOrder(p, size + 1);
    
    delete[] p;
    
    return 0;
    
}
