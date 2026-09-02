#include <iostream>
using namespace std;

#define MAXSIZE 5

int cq[MAXSIZE];
int front = -1;
int rear = -1;

bool isOverflow() {
    return ((rear + 1) % MAXSIZE == front);
}

bool isUnderflow() {
    return (front == -1);
}

void enqueue(int x) {
    if (isOverflow()) {
        cout << "Queue is Full!" << endl;
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAXSIZE;
    }

    cq[rear] = x;
    cout << x << " inserted successfully." << endl;
}

void dequeue() {
    if (isUnderflow()) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << cq[front] << " deleted successfully." << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAXSIZE;
    }
}

void peek() {
    if (isUnderflow()) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Front Element: " << cq[front] << endl;
}

void traverse() {
    if (isUnderflow()) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Queue Elements: ";

    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAXSIZE;
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== Circular Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                traverse();
                break;

            case 5:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}