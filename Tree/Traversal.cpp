#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Preorder Traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    // Creating Tree
    //        A
    //      /   \
    //     B     C
    //    / \   / \
    //   D   E F   G

    Node *root = new Node('A');

    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->right = new Node('E');

    root->right->left = new Node('F');
    root->right->right = new Node('G');

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}