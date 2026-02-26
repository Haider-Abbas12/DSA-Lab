#include "Queue.h"
#include <iostream>
using namespace std;

template<class ItemType>
Queue<ItemType>::Queue(int maxSize) {
    capacity = maxSize;
    items = new ItemType[capacity];
    front = 0;
    rear = -1;
    count = 0;
}

template<class ItemType>
Queue<ItemType>::Queue(const Queue& other) {
    CopyFrom(other);
}

template<class ItemType>
Queue<ItemType>::~Queue() {
    delete[] items;
}

template<class ItemType>
void Queue<ItemType>::CopyFrom(const Queue& other) {
    capacity = other.capacity;
    count = other.count;
    front = other.front;
    rear = other.rear;
    items = new ItemType[capacity];
    for (int i = 0; i < capacity; i++)
        items[i] = other.items[i];
}

template<class ItemType>
Queue<ItemType>& Queue<ItemType>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] items;
        CopyFrom(other);
    }
    return *this;
}

template<class ItemType>
bool Queue<ItemType>::IsEmpty() const {
    return count == 0;
}

template<class ItemType>
bool Queue<ItemType>::IsFull() const {
    return count == capacity;
}

template<class ItemType>
void Queue<ItemType>::Resize() {
    int newCapacity = capacity * 2;
    ItemType* newItems = new ItemType[newCapacity];
    for (int i = 0; i < count; i++)
        newItems[i] = items[(front + i) % capacity];
    delete[] items;
    items = newItems;
    front = 0;
    rear = count - 1;
    capacity = newCapacity;
}

template<class ItemType>
void Queue<ItemType>::Enqueue(ItemType newItem) {
    if (IsFull())
        Resize();
    rear = (rear + 1) % capacity;
    items[rear] = newItem;
    count++;
}

template<class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item) {
    if (IsEmpty()) return;
    item = items[front];
    front = (front + 1) % capacity;
    count--;
}

template<class ItemType>
ItemType Queue<ItemType>::Peek() const {
    if (IsEmpty()) return ItemType();
    return items[front];
}

template<class ItemType>
int Queue<ItemType>::Size() const {
    return count;
}

template<class ItemType>
int Queue<ItemType>::Capacity() const {
    return capacity;
}

template<class ItemType>
void Queue<ItemType>::Display() const {
    if (IsEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue (Front to Rear): ";
    for (int i = 0; i < count; i++)
        cout << items[(front + i) % capacity] << " ";
    cout << endl;
}