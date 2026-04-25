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
// Preorder Traversal: Root → Left → Right
// ─────────────────────────────────────────────
void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ─────────────────────────────────────────────
// Inorder Traversal: Left → Root → Right
// ─────────────────────────────────────────────
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ─────────────────────────────────────────────
// Postorder Traversal: Left → Right → Root
// ─────────────────────────────────────────────
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}