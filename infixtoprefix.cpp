#include <iostream>
using namespace std;

// Structure of tree node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Binary Tree class
class BinaryTree
{
    Node* root;
public:
    Node* createTree();
    void make()
    {
        root=createTree();
    }
    void preorderTraversal(Node* root);
};

// Create Binary Tree using recursion
Node* BinaryTree::createTree()
{
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* newNode = new Node;
    newNode->data = value;

    cout << "Enter left child of " << value << endl;
    newNode->left = createTree();

    cout << "Enter right child of " << value << endl;
    newNode->right = createTree();

    return newNode;
}

// Preorder Traversal using recursion
void BinaryTree::preorderTraversal(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    BinaryTree tree;   // Object created

    tree.make();

    return 0;
}
