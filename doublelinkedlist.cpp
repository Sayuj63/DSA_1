#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->prev = nullptr;
        new_node->next = head;
        if (head)
            head->prev = new_node;
        head = new_node;
    }

    void insertAtEnd(int value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = nullptr;
        if (!head) {
            new_node->prev = nullptr;
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }

    void deleteNode(int value) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) return;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp == head)
            head = temp->next;
        delete temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (!head) return;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value;
    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Delete a Node\n4. Display Forward\n5. Display Backward\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
          
             case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteNode(value);
                break;
            case 4:
                dll.displayForward();
                break;
            case 5:
                dll.displayBackward();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
