#include <iostream>
using namespace std;

#define MAXSIZE 5

int q[MAXSIZE];
int front=-1;
int rear=-1;


bool isOverflow() {
    return rear==MAXSIZE-1;
}


bool isUnderflow() {
    return front==-1;
}

void enqueue(int x) {
    if (isOverflow()) {
        cout << "queue if full"<< endl; 
        return;
    } else if(front==-1) {
       front=rear=0;
       q[rear]=x;
    }
    else{
        rear+=x;
        q[rear]=x;
    }
}


void dequeue() {
    if (isUnderflow()) {
        cout << "queue in empty" << endl;
        return;
    } else if(front==rear){
       front=rear=-1;
    }else{
        front=front+1;
    }
}


void peek() {
    if (isUnderflow()) {
        cout << "Queue is Empty!" << endl;
        return;
    } 
    cout<<q[front];
}


void traverse() {
    if (isUnderflow()) {
        cout << "Queue is Empty!" << endl;
        return;
    } else {
        cout << "Queue Elements: ";
        for (int i = front; i <=rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
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

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}