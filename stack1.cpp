 #include <iostream>
using namespace std;

#define MAX 10

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow. Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow. Cannot pop element." << endl;
        } else {
            cout << "Popped " << arr[top--] << " from the stack." << endl;
        }
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements are: ";
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

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

