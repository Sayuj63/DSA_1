#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = nullptr; }


    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


    void remove(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }


    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }


    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }


    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;
    
    do {
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
                
             case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (list.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 4:
                list.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";

         
        }
    } while (choice != 5);
    
    return 0;
}
