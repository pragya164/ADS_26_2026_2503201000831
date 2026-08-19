#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node*prev;
    Node*next;
};
Node*front = NULL;
Node*rear = NULL;

void dq_insertFront(int x)
{
  Node* newNode=new Node();
  newNode->info = x;

  if(front == NULL)
  {
    newNode->prev = NULL;
    newNode->next = NULL;
    front = rear = newNode;
  }
  else
  {
    front->prev = newNode;
    newNode->prev = NULL;
    newNode->next = front ;
    front = newNode;
  }
}

void dq_insertRear(int x)
{
  Node* newNode=new Node();
  newNode->info = x;

  if(rear == NULL)
  {
    newNode->prev = NULL;
    newNode->next = NULL;
    front = rear = newNode;
  }
  else
  {
    newNode->next = NULL;
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
  }
}

void dq_deleteFront()
{
    Node *temp = front;

    if(front == NULL)
    cout<<"Queue is empty";
    
    else if(front == rear)
    {
        front = rear = NULL;
        delete temp;
    }
    
    else
    {
       front = front->next;
       front->prev = NULL;
       delete temp;
    }
}

void dq_deleteRear()
{
    Node *temp = rear;
    if(rear == NULL)
    cout<<"Queue is empty";
    
    else if(front == rear)
    {
        front = rear = NULL;
        delete temp;
    }
    
    else
    {
       rear = rear->prev;
       rear->next = NULL;
       delete temp;
    }
}

void peekfront()
{
    if(front == NULL)
    cout<<"Queue is empty";
    else
    cout<<"Front Element: "<<front->info<<endl;
}

void peekrear()
{
    if(rear == NULL)
    cout<<"Queue is empty";
    else
    cout<<"Rear Element: "<<rear->info<<endl;
}

void traverse()
{
    if(front == NULL)
    cout<<"Queue is empty";
    else
    {
        Node* temp = front;
        while(temp!=rear)
        {
            cout<<temp->info<<"-> ";
            temp=temp->next;
        }
        cout<<rear->info<<"-> "; 
        cout<<"NULL"<<endl;
    }
}

int main()  
{
    int choice, value;

    do {
        cout << "1.insertFront" << endl;
        cout << "2.insertRear" << endl;
        cout << "3. DeleteFront" << endl;
        cout << "4. DeleteRear"<< endl;
        cout << "5. PeekFront"<< endl;
        cout << "6. PeekRear"<< endl;
        cout << "7. Traverse"<<endl;
        cout <<"8.Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dq_insertFront(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                dq_insertRear(value);
                break;

            case 3:
                dq_deleteFront();
                break;

            case 4:
                dq_deleteRear();
                break;


            case 5:
                peekfront();
                break;

            case 6:
                peekrear();
                break;

            case 7:             
               traverse();
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 8);
}