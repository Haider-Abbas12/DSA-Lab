#include "LinkedStr.h"

LinkedStr::LinkedStr() {
    ptr = NULL;
}

LinkedStr::~LinkedStr() {
    Node* temp;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len) {
    Node* temp;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    if (len <= 0) return;

    cout << "Enter " << len << " values:" << endl;

    for (int i = 0; i < len; i++) {
        int val;
        cin >> val;

        Node* newNode = new Node;
        newNode->info = val;
        newNode->next = NULL;

        if (ptr == NULL) {
            ptr = newNode;
        } else {
            Node* curr = ptr;
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = newNode;
        }
    }
}

void LinkedStr::displayStr() {
    if (ptr == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = ptr;
    cout << "List: ";
    while (curr != NULL) {
        cout << curr->info;
        if (curr->next != NULL) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

void LinkedStr::removeFirst() {
    if (ptr == NULL) return;

    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::removeLast() {
    if (ptr == NULL) return;

    if (ptr->next == NULL) {
        delete ptr;
        ptr = NULL;
        return;
    }

    Node* curr = ptr;
    while (curr->next->next != NULL)
        curr = curr->next;

    delete curr->next;
    curr->next = NULL;
}

void LinkedStr::remove(int k) {
    if (ptr == NULL) return;

    if (ptr->info == k) {
        removeFirst();
        return;
    }

    Node* curr = ptr;
    while (curr->next != NULL) {
        if (curr->next->info == k) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return;
        }
        curr = curr->next;
    }
}