#include "Min&Max.h"
#include <iostream>

void MinMaxStack::push(int value) {
    mainStack.push(value);
    
    if (minStack.empty() || value <= minStack.top()) {
        minStack.push(value);
    }
    
    if (maxStack.empty() || value >= maxStack.top()) {
        maxStack.push(value);
    }
}

void MinMaxStack::pop() {
    if (mainStack.empty()) {
        return;
    }
    
    int topValue = mainStack.top();
    mainStack.pop();
    
    if (!minStack.empty() && topValue == minStack.top()) {
        minStack.pop();
    }
    
    if (!maxStack.empty() && topValue == maxStack.top()) {
        maxStack.pop();
    }
}

int MinMaxStack::top() {
    if (mainStack.empty()) {
        return -1;
    }
    return mainStack.top();
}

int MinMaxStack::getMin() {
    if (minStack.empty()) {
        return -1;
    }
    return minStack.top();
}

int MinMaxStack::getMax() {
    if (maxStack.empty()) {
        return -1;
    }
    return maxStack.top();
}

bool MinMaxStack::isEmpty() {
    return mainStack.empty();
}

int MinMaxStack::size() {
    return mainStack.size();
}

void MinMaxStack::display() {
    if (mainStack.empty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    
    std::cout << "Stack size: " << size() << std::endl;
    std::cout << "Current minimum: " << getMin() << std::endl;
    std::cout << "Current maximum: " << getMax() << std::endl;
}

int main() {
    MinMaxStack stack;
    
    std::cout << "Pushing elements: 5, 2, 8, 1, 9, 3" << std::endl;
    stack.push(5);
    stack.push(2);
    stack.push(8);
    stack.push(1);
    stack.push(9);
    stack.push(3);
    
    std::cout << "\nCurrent Stack:" << std::endl;
    stack.display();
    
    std::cout << "\nPopping 2 elements" << std::endl;
    stack.pop();
    stack.pop();
    
    std::cout << "\nStack after popping:" << std::endl;
    stack.display();
    
    std::cout << "\nPushing elements: 15, 4" << std::endl;
    stack.push(15);
    stack.push(4);
    
    std::cout << "\nFinal Stack:" << std::endl;
    stack.display();
    
    return 0;
}