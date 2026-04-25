#include <iostream>
#include "Node.h"

using namespace std;

// ─────────────────────────────────────────────
// Function to create a new node dynamically
// ─────────────────────────────────────────────
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

// ─────────────────────────────────────────────
// Recursive function to count total number of nodes
// ─────────────────────────────────────────────
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ─────────────────────────────────────────────
// Recursive function to find height (maximum depth)
// Height = number of edges on longest root-to-leaf path
// ─────────────────────────────────────────────
int findHeight(Node* root) {
    if (root == NULL)
        return -1;
    int leftHeight  = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if (leftHeight > rightHeight)
        return leftHeight  + 1;
    else
        return rightHeight + 1;
}

// ─────────────────────────────────────────────
// Count and display all leaf nodes
// A leaf node has no left or right child
// ─────────────────────────────────────────────
int countAndDisplayLeaves(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return 1;
    }
    return countAndDisplayLeaves(root->left) + countAndDisplayLeaves(root->right);
}