#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* start = nullptr;

void display();
void insert_beg(int);
void insert_end(int);
void insert_after(int, int);
void delete_node(int);
void search_list();
int count();

int main() {
    int option, num, pos, c;
    do {
        cout << "\n\n****MAIN MENU****";
        cout << "\n1. Display List";
        cout << "\n2. Add node at beginning";
        cout << "\n3. Add node at end";
        cout << "\n4. Add node after a node";
        cout << "\n5. Delete a node";
        cout << "\n6. Search list";
        cout << "\n7. Count nodes in list";
        cout << "\n8. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> option;
        
        switch (option) {
            case 1:
                display();
                break;
            case 2:
                cout << "\nEnter the value to be inserted: ";
                cin >> num;
                insert_beg(num);
                break;
            case 3:
                cout << "\nEnter the value to be inserted: ";
                cin >> num;
                insert_end(num);
                break;
            case 4:
                cout << "\nEnter the value to be inserted: ";
                cin >> num;
                cout << "\nEnter the position after which the value is to be inserted: ";
                cin >> pos;
                insert_after(num, pos);
                break;
            case 5:
                cout << "\nEnter the value to delete: ";
                cin >> num;
                delete_node(num);
                break;
            case 6:
                search_list();
                break;
            case 7:
                c = count();
                if (c != 0)
                    cout << "\nNumber of nodes in the list: " << c;
                break;
        }
    } while (option != 8);
    
    return 0;
}

void display() {
    node* ptr = start;
    if (ptr == nullptr)
        cout << "\nLinked list is empty";
    else {
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

void insert_beg(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->next = start;
    start = newNode;
}

void insert_end(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->next = nullptr;
    if (start == nullptr) {
        start = newNode;
    } else {
        node* temp = start;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insert_after(int value, int afterValue) {
    node* temp = start;
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "\nValue not found!";
        return;
    }
    
    node* newNode = new node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_node(int value) {
    if (start == nullptr) {
        cout << "\nList is empty!";
        return;
    }
    
    if (start->data == value) {
        node* temp = start;
        start = start->next;
        delete temp;
        return;
    }
    
    node* temp = start;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    
    if (temp->next == nullptr) {
        cout << "\nValue not found!";
        return;
    }
    
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void search_list() {
    int value, pos = 1;
    bool found = false;
    cout << "\nEnter value to search: ";
    cin >> value;
    node* temp = start;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "\nValue found at position: " << pos;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << "\nValue not found in the list!";
}

int count() {
    int count = 0;
    node* temp = start;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}