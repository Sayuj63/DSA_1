//9. Implement a linear queue using an array and perform dequeue, and display operations.

#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int arr[100];
    
public:
    Queue() { front = -1; rear = -1; }
    
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front++] << " dequeued from queue" << endl;
        if (front > rear) front = rear = -1;
    }
    
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    
    do {
        cout << "\n1. Dequeue\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                q.dequeue();
                break;
            case 2:
                q.display();
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
