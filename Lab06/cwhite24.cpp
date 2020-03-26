//
//  yourid.cpp
//  
//
//  Created by Henry White on 17/03/2020.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <list>
#include <utility>

using namespace std;

//Create Hash Object
class Hash {
    int Container;
    list<int> *table;
    
public:
    Hash(int x);
    int hashFunction(int y);
    void hashInsert(int key);
    void hashSearch(int key, int m);
    void hashDelete(int key);
    void hashDisplay(int m);
    void hashPrint(int key, int code, int m, int index);
};

//Constructor
Hash::Hash(int x) {
    this->Container = x;
    table = new list<int>[Container];
}

//Funciton to handle outputs
void Hash::hashPrint(int key, int code, int m, int index) {
    if (code == 1) {
        cout << key << ":NOT_FOUND;" << endl;
    }
    else if (code == 2) {
        cout << key << ":FOUND_AT" << (key % m) << "," << index << ";" << endl;
    }
    else if (code == 3) {
        cout << key << ":DELETED;" << endl;
    }
    else if (code == 4) {
        cout << key << ":DELETE_FAILED;" << endl;
    }
}

//Hash function [h(k) = k mod m
int Hash::hashFunction(int y) {
    int temp;
    temp = y % Container;
    return (temp);
}

//Function that allows inserting into hash table
void Hash::hashInsert(int key) {
    int index = hashFunction(key);
    table[index].push_front(key);
}

//Funciton to search for a specific key in the hash table
void Hash::hashSearch(int key, int m) {
    list<int> l = table[key % m];
    int index = 0;
    list<int>::iterator it;
    if (l.empty()) {
        hashPrint(key, 1, m, index);
    }
    else {
        for (it = l.begin(); it != l.end(); it++) {
            if (*it == key) {
                hashPrint(key, 2, m, index);
                return;
            }
            index++;
        }
        hashPrint(key, 1, m, index);
    }
}

//Function to delete an element from hash table.
void Hash::hashDelete(int key) {
    int index = hashFunction(key);
    bool isFound = false;
    list<int>::iterator it;
    for (it = table[index].begin(); it != table[index].end(); it++) {
        if (*it == key) {
            isFound = true;
            break;
        }
    }
    if (it != table[index].end()) {
        table[index].erase(it);
        hashPrint(key, 3, 0, index);
    }
    if (!isFound) {
        hashPrint(key, 4, 0, index);
    }
}

//Funciton that displays hash table
void Hash::hashDisplay(int m) {
    list<int> l;
    list<int>::iterator it;
    for (int i = 0; i < m; i++) {
        l = table[i];
        if(l.empty()) {
            cout << i << ":;" << endl;
        }
        else {
            cout << i << ":";
            for (it = l.begin(); it != l.end(); it++) {
                cout << *it << "->";
            }
            cout << ";" << endl;
        }
    }
}

//Driver Function
int main(int argc, const char * argv[]) {
    int m;
    cin >> m;
    Hash H(m);
    int key;
    char command;
    do {
        cin >> command;
        
        if (command == 'i') {
            cin >> key;
            H.hashInsert(key);
        }
        else if (command == 'd') {
            cin >> key;
            H.hashDelete(key);
        }
        else if (command == 's') {
            cin >> key;
            H.hashSearch(key, m);
        }
        else if (command == 'o') {
            H.hashDisplay(m);
        }
    } while (command != 'e');
    
    return 0;
}



