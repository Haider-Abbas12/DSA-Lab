#pragma once
#include <stack>
using namespace std;

template<class ItemType>
class Queue {
private:
    ItemType* items;
    int front;
    int rear;
    int count;
    int capacity;

    void CopyFrom(const Queue& other);
    void Resize();

public:
    Queue(int maxSize = 5);
    Queue(const Queue& other);
    ~Queue();
    Queue& operator=(const Queue& other);

    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    ItemType Peek() const;
    int Size() const;
    void Display() const;
};