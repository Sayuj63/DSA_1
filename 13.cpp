//13. WAP to Singly linked list data structure & perform insert at particular position and display operations.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
    Node* head;
    
public:
    SinglyLinkedList() { head = nullptr; }
    
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        cout << "Linked List elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, position;
    
    do {
        cout << "\n1. Insert at Position\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
    
    return 0;
}
