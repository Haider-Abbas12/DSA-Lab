#ifndef LINKEDSTR_H
#define LINKEDSTR_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedStr {
private:
    Node* ptr;
public:
    LinkedStr();
    ~LinkedStr();
    void makeStr(int len);
    void displayStr();
    void removeFirst();
    void removeLast();
    void remove(int k);
};

#endif