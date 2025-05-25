#include <iostream>

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node with data
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Class to manage the operations on the Doubly Linked List
class DoublyLinkedList {
    Node* head;

public:
    // Constructor to initialize the head pointer
    DoublyLinkedList() {
        head = NULL;
    }

    // Function declarations
    void insertAtFront(int value);
    void insertAtEnd(int value);
    void deleteFromFront();
    void deleteFromEnd();
    void display();
};

// Function to insert a node at the front of the list
void DoublyLinkedList::insertAtFront(int value) {
    Node* newNode = new Node(value);  // Create a new node

    if (head == NULL) {  // If the list is empty
        head = newNode;     // Make the new node the head
    } else {
        newNode->next = head;  // Point new node to current head
        head->prev = newNode;  // Set current head's prev to new node
        head = newNode;        // Move head to the new node
    }
    std::cout << value << " inserted at the front.\n";
}

// Function to insert a node at the end of the list
void DoublyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);  // Create a new node

    if (head == NULL) {  // If the list is empty
        head = newNode;     // Make the new node the head
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;   // Point last node's next to new node
        newNode->prev = temp;   // Set new node's prev to last node
    }
    std::cout << value << " inserted at the end.\n";
}

// Function to delete a node from the front of the list
void DoublyLinkedList::deleteFromFront() {
    if (head == NULL) {  // List is empty
        std::cout << "List is empty. Cannot delete from front.\n";
        return;
    }

    Node* temp = head;
    head = head->next;  // Move head to the next node
    if (head != NULL) {
        head->prev = NULL;  // Set new head's prev to NULL
    }
    std::cout << "Deleted " << temp->data << " from the front.\n";
    delete temp;  // Free the memory of the old head
}

// Function to delete a node from the end of the list
void DoublyLinkedList::deleteFromEnd() {
    if (head == NULL) {  // List is empty
        std::cout << "List is empty. Cannot delete from end.\n";
        return;
    }

    Node* temp = head;
    if (temp->next == NULL) {  // Only one node in the list
        head = NULL;  // Set head to NULL
        std::cout << "Deleted " << temp->data << " from the end.\n";
        delete temp;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }

    temp->prev->next = NULL;  // Set second-last node's next to NULL
    std::cout << "Deleted " << temp->data << " from the end.\n";
    delete temp;  // Free the memory of the last node
}

// Function to display the list
void DoublyLinkedList::display() {
    if (head == NULL) {  // List is empty
        std::cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    std::cout << "Doubly Linked List: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";  // Print the node's data
        temp = temp->next;  // Move to the next node
    }
    std::cout << "\n";
}

// Main function to provide a menu for user interaction
int main() {
    DoublyLinkedList dll;  // Create a Doubly Linked List object
    int choice, value;

    while (true) {
        // Display menu for user operations
        std::cout << "\nDoubly Linked List Operations:\n";
        std::cout << "1. Insert at front\n";
        std::cout << "2. Insert at end\n";
        std::cout << "3. Delete from front\n";
        std::cout << "4. Delete from end\n";
        std::cout << "5. Display list\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Switch case to perform the appropriate action
        switch (choice) {
            case 1:
                std::cout << "Enter the value to insert at front: ";
                std::cin >> value;
                dll.insertAtFront(value);
                break;

            case 2:
                std::cout << "Enter the value to insert at end: ";
                std::cin >> value;
                dll.insertAtEnd(value);
                break;

            case 3:
                dll.deleteFromFront();
                break;

            case 4:
                dll.deleteFromEnd();
                break;

            case 5:
                dll.display();
                break;

            case 6:
                std::cout << "Exiting...\n";
                return 0;

            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

