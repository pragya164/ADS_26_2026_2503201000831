#include <iostream>
using namespace std;

#define MAXSIZE 5

int arr[MAXSIZE], size = 0;

void enque(int value) {
    if (size == MAXSIZE) {
        cout << "Priority Queue is Full!" << endl;
        return;
    }

    arr[size] = value;
    size++;

    cout << value << " inserted successfully." << endl;
}

void deque() {
    if (size == 0) {
        cout << "Priority Queue is Empty!" << endl;
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << arr[maxIndex] << " deleted successfully." << endl;

    for (int i = maxIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void peek() {
    if (size == 0) {
        cout << "Priority Queue is Empty!" << endl;
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << "Maximum Element: " << arr[maxIndex] << endl;
}

void display() {
    if (size == 0) {
        cout << "Priority Queue is Empty!" << endl;
        return;
    }

    cout << "Priority Queue Elements: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n===== Priority Queue Menu =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enque(value);
                break;

            case 2:
                deque();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
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