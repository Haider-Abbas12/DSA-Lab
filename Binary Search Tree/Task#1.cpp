#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class BST {
private:
    Node* root;

    Node* insertHelper(Node* node, int value);
    Node* retrieveHelper(Node* node, int value);

public:
    BST();
    void InsertItem(int value);
    bool RetrieveItem(int value);
};

Node::Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
}

BST::BST() {
    root = NULL;
}

Node* BST::insertHelper(Node* node, int value) {
    if (node == NULL) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insertHelper(node->left, value);
    } else if (value > node->data) {
        node->right = insertHelper(node->right, value);
    }
    return node;
}

Node* BST::retrieveHelper(Node* node, int value) {
    if (node == NULL) {
        return NULL;
    }
    if (value == node->data) {
        return node;
    } else if (value < node->data) {
        return retrieveHelper(node->left, value);
    } else {
        return retrieveHelper(node->right, value);
    }
}

void BST::InsertItem(int value) {
    root = insertHelper(root, value);
}

bool BST::RetrieveItem(int value) {
    Node* result = retrieveHelper(root, value);
    return result != NULL;
}

int main() 
{
    BST tree;

    tree.InsertItem(45);
    tree.InsertItem(25);
    tree.InsertItem(60);
    tree.InsertItem(15);
    tree.InsertItem(30);
    tree.InsertItem(50);
    tree.InsertItem(75);
    tree.InsertItem(10);
    tree.InsertItem(28);
    tree.InsertItem(48);
    tree.InsertItem(85);

    cout << "========================================" << endl;
    cout << "   BST Successfully Created!" << endl;
    cout << "   Tree Values: 45 25 60 15 30 50 75" << endl;
    cout << "                10 28 48 85" << endl;
    cout << "========================================" << endl;

    char choice;

    do {
        int searchValue;

        cout << "\nEnter a value to search: ";

        if (!(cin >> searchValue)) {
            cout << "Invalid input! Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Do you want to search again? (y/n): ";
            cin >> choice;
            continue;
        }

        if (searchValue < 0) {
            cout << "Note: Searching for negative value (" << searchValue << ")..." << endl;
        }

        if (searchValue == 0) {
            cout << "Note: Searching for zero..." << endl;
        }

        if (searchValue > 10000) {
            cout << "Note: Searching for a very large value (" << searchValue << ")..." << endl;
        }

        bool found = tree.RetrieveItem(searchValue);

        cout << "----------------------------------------" << endl;
        if (found) {
            cout << "Result: " << searchValue << " was FOUND in the BST." << endl;
        } else {
            cout << "Result: " << searchValue << " was NOT FOUND in the BST." << endl;
        }
        cout << "----------------------------------------" << endl;

        cout << "Do you want to search again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}