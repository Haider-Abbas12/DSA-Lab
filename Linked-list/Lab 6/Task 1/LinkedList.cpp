#include "LinkedList.h"

LinkedList::LinkedList() {
    ptr = NULL;
}

LinkedList::~LinkedList() {
    Node* temp;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

// Insert at beginning
void LinkedList::push(int val) {
    Node* newNode = new Node;
    newNode->info = val;
    newNode->next = ptr;
    ptr = newNode;
    display();
}

// Insert after a given value
void LinkedList::insertAfter(int target, int val) {
    Node* curr = ptr;
    while (curr != NULL) {
        if (curr->info == target) {
            Node* newNode = new Node;
            newNode->info = val;
            newNode->next = curr->next;
            curr->next = newNode;
            display();
            return;
        }
        curr = curr->next;
    }
    cout << "Value " << target << " not found in list." << endl;
}

// Delete first node with given value
void LinkedList::deleteVal(int val) {
    if (ptr == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (ptr->info == val) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
        display();
        return;
    }
    Node* curr = ptr;
    while (curr->next != NULL) {
        if (curr->next->info == val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            display();
            return;
        }
        curr = curr->next;
    }
    cout << "Value " << val << " not found in list." << endl;
}

// Remove from beginning
void LinkedList::pop() {
    if (ptr == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
    display();
}

// Display all elements
void LinkedList::display() {
    if (ptr == NULL) {
        cout << "List: NULL" << endl;
        return;
    }
    Node* curr = ptr;
    cout << "List: ";
    while (curr != NULL) {
        cout << curr->info << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// Check if empty
bool LinkedList::isEmpty() {
    return ptr == NULL;
}