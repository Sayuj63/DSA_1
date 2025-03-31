//11. Implement a circular queue using an array and perform dequeue, and display operations.

#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int arr[100];
    
public:
    CircularQueue(int s) { front = rear = -1; size = s; }
    
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
    
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
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
