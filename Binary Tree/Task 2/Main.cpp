#include <iostream>
#include "Node.h"
#include "Binarytree.cpp"

using namespace std;

Node* createNode           (int value);
int   countNodes           (Node* root);
int   findHeight           (Node* root);
int   countAndDisplayLeaves(Node* root);

int main() 
{

    Node* root = createNode(50);

    root->left  = createNode(30);
    root->right = createNode(80);

    root->left->left   = createNode(20);
    root->left->right  = createNode(40);

    root->right->left  = createNode(70);
    root->right->right = createNode(90);

    // ── Function 1: Count total nodes ──
    int total = countNodes(root);
    cout << "Total Number of Nodes : " << total << endl;

    // ── Function 2: Height of tree ──
    int height = findHeight(root);
    cout << "Height of Tree        : " << height << endl;

    // ── Function 3: Leaf nodes ──
    cout << "Leaf Nodes            : ";
    int leaves = countAndDisplayLeaves(root);
    cout << endl;
    cout << "Total Leaf Nodes      : " << leaves << endl;

    return 0;
}