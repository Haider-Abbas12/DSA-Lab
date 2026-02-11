#ifndef MINMAX_H
#define MINMAX_H

#include <stack>

class MinMaxStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
    std::stack<int> maxStack;

public:
    void push(int value);
    void pop();
    int top();
    int getMin();
    int getMax();
    bool isEmpty();
    int size();
    void display();
};

#endif