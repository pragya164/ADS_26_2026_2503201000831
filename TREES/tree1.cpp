#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create() {
    int x;
    cout << "Enter data (-1 for no data): ";
    cin >> x;

    if (x == -1)
        return NULL;

    Node* newNode = new Node();

    newNode->data = x;

    cout << "Enter left child of " << x << ": ";
    newNode->left = create();

    cout << "Enter right child of " << x << ": ";
    newNode->right = create();

    return newNode;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = create();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}