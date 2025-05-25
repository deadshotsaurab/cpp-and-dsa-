#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() { head = nullptr; }

    // Insert a node at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted into the list\n";
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // If the node to be deleted is the head node
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list\n";
            return;
        }

        // Find the node to be deleted
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Element " << value << " not found in the list\n";
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << value << " deleted from the list\n";
        }
    }

    // Display all nodes in the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
        } else {
            Node* temp = head;
            cout << "Linked list elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

