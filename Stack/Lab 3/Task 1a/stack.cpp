#include "stack.h"
template<class ItemType>

Stack<ItemType>:: Stack() 
{
    maxStack = 500;
    top = -1;
    items = new ItemType [500];
}
template<class ItemType>

Stack<ItemType>:: Stack(int max) 
{
    maxStack = max;
    top = -1;
    items = new ItemType [max];
}

template<class ItemType>

Stack<ItemType>:: ~Stack() 
{
    delete[] items;
}

 
template<class ItemType>
int Stack<ItemType>::IsEmpty() const { return (top== -1);
}

template<class ItemType>
int Stack<ItemType>::IsFull() const { return (top== maxStack - 1);
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType newitem) {
if	(IsFull()) {
cout << "Stack Overflow"<< endl; 
exit(1);
}
top++;
items[top] = newitem;
}

template<class ItemType>
void Stack<ItemType>::Pop(ItemType& item) { if (IsEmpty()) {
cout << "Stack Underflow"<< endl; 
exit(1);
}
item= items[top]; top--;
}