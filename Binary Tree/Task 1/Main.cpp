#include <iostream>
#include "Node.h"
#include "Binarytree.cpp"
using namespace std;

Node* createNode(int value);
void  preorder  (Node* root);
void  inorder   (Node* root);
void  postorder (Node* root);

int main() 
{

    Node* root    = createNode(50);

    root->left    = createNode(30);
    root->right   = createNode(80);

    root->left->left  = createNode(20);
    root->left->right = createNode(40);

    root->right->left  = createNode(70);
    root->right->right = createNode(90);

    // ── Display all three traversals ──
    cout << "Preorder  Traversal (Root->Left->Right) : ";
    preorder(root);
    cout << endl;

    cout << "Inorder   Traversal (Left->Root->Right) : ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal (Left->Right->Root) : ";
    postorder(root);
    cout << endl;

    return 0;
}