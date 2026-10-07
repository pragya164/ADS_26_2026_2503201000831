#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create Binary Tree
Node* create()
{
    int x;

    cout << "Enter data (-1 for no node): ";
    cin >> x;

    if (x == -1)
        return NULL;

    Node *newNode = new Node();
    newNode->data = x;

    cout << "Enter left child of " << x << ": ";
    newNode->left = create();

    cout << "Enter right child of " << x << ": ";
    newNode->right = create();

    return newNode;
}

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

// Count Leaf Nodes
int leafCount(Node *p)
{
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 1;

    return leafCount(p->left) + leafCount(p->right);
}

//internal node count
int internalCount(Node *p)
{
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 0;   // leaf node

    return 1 + internalCount(p->left) + internalCount(p->right);
}

int totalNodes(Node*p){
    
    if(p==NULL)
        return 0;

    return 1 + totalNodes(p->left) + totalNodes(p->right);
}

int main()
{
    Node *root = create();

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << "\n\nTotal Leaf Nodes = "
         << leafCount(root);
    cout << "\nTotal Internal Nodes = " 
    << internalCount(root);

    cout << "\nTotal Nodes = "
         << totalNodes(root);
    return 0;
}


