//10. Implement a circular queue using an array and perform enqueue, and display operations.

#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int arr[100];
    
public:
    CircularQueue(int s) { front = rear = -1; size = s; }
    
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        cout << value << " enqueued into queue" << endl;
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
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
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
