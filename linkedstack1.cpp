#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}


void deleteNode(Node*& head, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << value << " deleted.\n";
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value)
        temp = temp->next;
    if (!temp->next) {
        cout << "Element not found.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << value << " deleted.\n";
}


void search(Node* head, int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            cout << value << " found in the list.\n";
            return;
        }
        temp = temp->next;
    }
    cout << value << " not found.\n";
}

void display(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {
    Node* head = nullptr;
    int choice, value;
    
    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete a node\n";
        cout << "4. Search for an element\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
