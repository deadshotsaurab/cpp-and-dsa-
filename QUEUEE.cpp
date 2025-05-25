#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear >= MAX - 1) {
            cout << "Queue Overflow. Cannot enqueue " << value << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << "Enqueued " << value << " to the queue." << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow. Cannot dequeue element." << endl;
        } else {
            cout << "Dequeued " << arr[front++] << " from the queue." << endl;
            if (front > rear) front = rear = -1;
        }
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

