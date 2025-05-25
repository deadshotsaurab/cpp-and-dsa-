#include <iostream>
#define MAX 100 // Maximum size of the queue

using namespace std;

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue overflow\n";
        } else {
            if (front == -1) front = 0; // Initialize front if inserting first element
            arr[++rear] = value;
            cout << value << " enqueued to the queue\n";
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow\n";
        } else {
            cout << arr[front++] << " dequeued from the queue\n";
            if (front > rear) { // Reset queue if it becomes empty
                front = -1;
                rear = -1;
            }
        }
    }

    // Peek (Front) operation
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element is " << arr[front] << endl;
        }
    }

    // Display queue elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
        } else {
            cout << "Queue elements: ";
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

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek (Front)\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.peek();
                break;
            case 4:
                queue.display();
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

