#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedList {
private:
    Node* ptr;
public:
    LinkedList();
    ~LinkedList();
    void push(int val);
    void insertAfter(int target, int val);
    void deleteVal(int val);
    void pop();
    void display();
    bool isEmpty();
};

#endif