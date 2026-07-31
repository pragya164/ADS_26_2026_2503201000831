#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

Node *front = NULL;
Node*rear=NULL;


// bool isEmpty() {
//     return top == NULL;
// }


void enqueue(int value) {
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;
    if(front==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }

    cout << value << " pushed into queue." << endl;
 }


void dequeue() {
    if (front==NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    else if(front==rear){
        Node*temp=front;
        front=rear=NULL;
        delete (temp);
    }
  else{  Node *temp = front;
    front=front->next;
    delete temp;
}
}

void peek() {
    if (front==NULL) {
        cout << " Queue is Empty!" << endl;
    } else {
        cout<< "front element:"<< front->data << endl;
    }
}


void display() {
    if (front==NULL) {
        cout << "Queue is Empty!" << endl;

    Node *temp = front;
    cout << "Queue Elements: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
}
int main() {
    int choice, value;

    do {
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "Enter choice: ";
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
                display();
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}