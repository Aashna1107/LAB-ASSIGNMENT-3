#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;


bool isEmpty() {
    return top == -1;
}


bool isFull() {
    return top == MAX - 1;
}


void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        stackArr[++top] = x;
        cout << x << " pushed into stack.\n";
    }
}


void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop.\n";
    } else {
        cout << stackArr[top--] << " popped from stack.\n";
    }
}


void peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top element: " << stackArr[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. isEmpty\n";
        cout << "6. isFull\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
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
            case 5:
                cout << (isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 6:
                cout << (isFull() ? "Stack is full.\n" : "Stack is not full.\n");
                break;
            case 7:
                cout << "Exiting program...\n";
                return 0;  // ?? Ends program here
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}


