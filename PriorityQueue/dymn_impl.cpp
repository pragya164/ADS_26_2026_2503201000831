#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

Node *maxNode = NULL;
Node *maxPrev = NULL;

void insert(int x)
{
    Node *newNode = new Node;
    newNode->info = x;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteElement(){
    Node *temp = front;

    maxNode = front;
    maxPrev = NULL;

    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info > maxNode->info)
        {
            maxNode = temp;
            maxPrev = prev;
        }

        prev = temp;
        temp = temp->next;
    }

    if (maxNode == front)
    {
        front = front->next;
        delete maxNode;
        return;
    }

    maxPrev->next = maxNode->next;

    if (maxNode == rear)
        rear = maxPrev;

    delete maxNode;
}

void peek()
{
    Node *temp = front;

    maxNode = front;
    maxPrev = NULL;

    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->info > maxNode->info)
        {
            maxNode = temp;
            maxPrev = prev;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Max Element = " << maxNode->info << endl;
}

void display()
{
    Node *temp = front;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert(10);
    insert(20);
    insert(50);
    insert(15);
    insert(5);

    display();

    peek();

     deleteElement();

    display();

    return 0;
}