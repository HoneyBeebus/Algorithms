//
//  randTest.cpp
//  
//
//  Created by Henry White on 04/03/2020.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;



int random(int a, int b) {
    int c;
    c = rand() % (a + b);
    return (c);
}

//driver function
int main(int argc, char **argv) {
    int a;
    int b;
    cin >> a;
    cin >> b;
    for (int i = a; i <= b; i++) {
        cout << random(a, b) << endl;
    }
    
}

