//
//  yourid.cpp
//  
//
//  Created by Henry White on 30/03/2020.
//

#include <stdio.h>
#include <iostream>
#include <limits.h>

using namespace std;

//Rod cutting algorithm from CLRS
int cutRod(int * p, int n) {
    if (n == 0) {
        return 0;
    }
    int q = -2147483647;
    for (int i = 0; i < n; i++) {
        q = max(q,p[i] + cutRod(p, n - i - 1));
    }
    return q;
}

//Driver Function
int main (int argc, char ** argv) {
    int size;
    int *Sequence;
    int maxRevenue;
    
    cin >> size;
    Sequence = new int[size];
    
    for (int i = 0; i < size; i++) {
        cin >> Sequence[i];
    }
    
    maxRevenue = cutRod(Sequence, size);
    
    cout << maxRevenue << endl;
    
    int x = 0;
    int y = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (x == 0 && y == 0 && i!=j && Sequence[i] + Sequence[j] == maxRevenue) {
                x = i + 1;
                y = j + 1;
            }
        }
    }
    
    cout << x << " " << y << " " << -1 << endl;
    
    delete[] Sequence;
}
