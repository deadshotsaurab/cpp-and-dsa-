#include <iostream>
#define MAX 100 // Maximum size of the stack

using namespace std;

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Push operation
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack overflow\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed into the stack\n";
        }
    }

    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack underflow\n";
        } else {
            cout << arr[top--] << " popped from the stack\n";
        }
    }

    // Peek operation
    void peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element is " << arr[top] << endl;
        }
    }

    // Display stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

