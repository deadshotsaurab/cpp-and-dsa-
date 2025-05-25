#include <iostream>
using namespace std;

#define MAX 10

class PriorityQueue {
    int arr[MAX];
    int priority[MAX];
    int size;

public:
    PriorityQueue() { size = 0; }

    void enqueue(int value, int prio) {
        if (size >= MAX) {
            cout << "Priority Queue Overflow. Cannot enqueue " << value << endl;
            return;
        }

        int i;
        for (i = size - 1; i >= 0; i--) {
            if (priority[i] < prio) {
                arr[i + 1] = arr[i];
                priority[i + 1] = priority[i];
            } else {
                break;
            }
        }

        arr[i + 1] = value;
        priority[i + 1] = prio;
        size++;

        cout << "Enqueued " << value << " with priority " << prio << " to the priority queue." << endl;
    }

    void dequeue() {
        if (size <= 0) {
            cout << "Priority Queue Underflow. Cannot dequeue element." << endl;
        } else {
            cout << "Dequeued " << arr[0] << " with priority " << priority[0] << " from the priority queue." << endl;
            for (int i = 1; i < size; i++) {
                arr[i - 1] = arr[i];
                priority[i - 1] = priority[i];
            }
            size--;
        }
    }

    void display() {
        if (size <= 0) {
            cout << "Priority Queue is empty." << endl;
        } else {
            cout << "Priority Queue elements (value, priority): ";
            for (int i = 0; i < size; i++) {
                cout << "(" << arr[i] << ", " << priority[i] << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, value, prio;

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
                cout << "Enter priority for the value: ";
                cin >> prio;
                pq.enqueue(value, prio);
                break;

            case 2:
                pq.dequeue();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

