#include <iostream>
using namespace std;

#define MAXSIZE 5

int st[MAXSIZE];
int top = -1;


bool isOverflow() {
    return top == MAXSIZE - 1;
}


bool isUnderflow() {
    return top == -1;
}

void push(int value) {
    if (isOverflow()) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        st[top] = value;
        cout << value << " pushed into stack." << endl;
    }
}


void pop() {
    if (isUnderflow()) {
        cout << "Stack Underflow!" << endl;
    } else {
        cout << st[top] << " popped from stack." << endl;
        top--;
    }
}


void peek() {
    if (isUnderflow()) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Top Element = " << st[top] << endl;
    }
}


void traverse() {
    if (isUnderflow()) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Stack Elements: ";
        for (int i = top; i >= 0; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "Enter your choice: ";
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
                traverse();
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}