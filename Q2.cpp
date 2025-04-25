// Q2. 
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    }; 
class circularlink {
    public:
    Node*head;
    circularlink() {
    head= NULL;
    }

void insertatbegin(int data) {
    Node* newnode = new Node();
    newnode->data = data;
        if (head == NULL) {
        head =newnode;
        newnode->next =head;
        }
       
        else {
        newnode->next= head;
        Node* temp =head;
        
        while (temp->next != head) {
        temp =temp->next;
        }
        temp->next =newnode;
        head= newnode;
        }
        }
        
        void display() {
            Node* temp = head;
            if (head == NULL) {
                cout <<"Empty list" <<endl;
                return;
                }
                do {
                    cout <<temp->data<< " ";
                    temp = temp->next;
                    } while(temp != head);
                    cout<< endl;
                    }
                    };
                    
int main() {
            circularlink c;
            c.insertatbegin(2);
            c.insertatbegin(4);
            c.insertatbegin(6);
            c.display();
            return 0;
             }

