#include <iostream>
#include <stack>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

void reverseFirstK(Queue<int>& q, int k) {
    if (k <= 0 || k > q.Size()) {
        cout << "Invalid K!" << endl;
        return;
    }

    stack<int> st;
    int val;

    for (int i = 0; i < k; i++) {
        q.Dequeue(val);
        st.push(val);
    }

    while (!st.empty()) {
        q.Enqueue(st.top());
        st.pop();
    }

    int remaining = q.Size() - k;
    for (int i = 0; i < remaining; i++) {
        q.Dequeue(val);
        q.Enqueue(val);
    }
}

int main() {

    int n, k;

    cout << "Enter total number of elements: ";
    cin >> n;

    Queue<int> q(n);
    for (int i = 1; i <= n; i++)
        q.Enqueue(i);

    

    cout << "Enter K (elements to reverse): ";
    cin >> k;
    cout << "Before: "; q.Display();
    reverseFirstK(q, k);
    cout << "After:  "; q.Display();

    return 0;
}