#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template<class ItemType>

class Stack 
{

public:

    Stack();
    Stack(int max);
    ~Stack();
    int IsEmpty() const;
    int IsFull() const;
    void Push(ItemType newItem);
    void Pop(ItemType& item);

private:

    int top;
    int maxStack;
    ItemType* items;

};
