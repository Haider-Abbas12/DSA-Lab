#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main ()
{
    cout << "Task 1: Dynamic Queue" << endl;
    cout << "\n-----Integer Queue(capacity 3)-----" << endl;
    Queue<int> q(3);

    for (int i=1; i<=6; i++)
    {
        q.Enqueue(i * 10);
    }
    q.Display();
    cout << "Size: " << q.Size() << endl;
    cout << "Capacity: " << q.Capacity() << endl;
    cout << "Peek: " << q.Peek() << endl;

    int val;
    q.Dequeue(val);
    q.Dequeue(val);
    cout << "\nAfter Dequeue 2 items:" << endl;
    q.Display();

    cout << "\n-- String Queue (capacity 2) --" << endl;
    Queue<string> sq(2);
    sq.Enqueue("Ali");
    sq.Enqueue("Adullah");
    sq.Enqueue("Ahsan");
    sq.Enqueue("Ammar");  
    sq.Display();
    cout << "Size: " << sq.Size() << endl;
    cout << "Capacity: " << sq.Capacity() << endl;

    cout << "\n-- Empty Queue Edge Case --" << endl;
    Queue<int> empty(5);
    cout << "IsEmpty: " << (empty.IsEmpty() ? "true" : "false") << endl;
    empty.Dequeue(val);  
    cout << "Peek on empty: " << empty.Peek() << endl;

    return 0;
}
