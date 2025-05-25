#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Priority queue of integers (by default, max-heap)
    priority_queue<int> pq;

    int choice, value;
    
    while (true) {
        cout << "Priority Queue Operations:\n";
        cout << "1. Insert element\n";
        cout << "2. Extract maximum element\n";
        cout << "3. Display top element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                pq.push(value);
                cout << value << " inserted into the priority queue.\n";
                break;
            
            case 2:
                if (!pq.empty()) {
                    cout << "Maximum element " << pq.top() << " extracted from the priority queue.\n";
                    pq.pop();
                } else {
                    cout << "Priority queue is empty.\n";
                }
                break;

            case 3:
                if (!pq.empty()) {
                    cout << "Top element is: " << pq.top() << endl;
                } else {
                    cout << "Priority queue is empty.\n";
                }
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}

