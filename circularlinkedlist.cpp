#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() { head = nullptr; }

    void insertAfter(int key, int new_data) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* new_node = new Node();
                new_node->data = new_data;
                new_node->next = temp->next;
                temp->next = new_node;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertAtEnd(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        if (!head) {
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head, *prev = nullptr;
        while (temp->data != key) {
            prev = temp;
            temp = temp->next;
            if (temp == head) return;
        }
        if (temp == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = head->next;
            prev->next = head;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, key;
    while (true) {
        cout << "\n1. Insert at End\n2. Insert After a Node\n3. Delete a Node\n4. Display List\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter key node value: ";
                cin >> key;
                cout << "Enter value to insert after " << key << ": ";
                cin >> value;
                cll.insertAfter(key, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                cll.deleteNode(value);
                break;
            case 4:
                cll.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
