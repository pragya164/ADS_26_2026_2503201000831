#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

Node *top = NULL;


bool isEmpty() {
    return top == NULL;
}


void push(int value) {
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << value << " pushed into stack." << endl;
}


void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return;
    }

    Node *temp = top;
    cout << top->data << " popped from stack." << endl;
    top = top->next;
    delete temp;
}


void peek() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Top Element = " << top->data << endl;
    }
}


void display() {
    if (isEmpty()) {
        cout << "Stack is Empty!" << endl;
        return;
    }

    Node *temp = top;
    cout << "Stack Elements: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}