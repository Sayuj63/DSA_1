//12. Implement a double ended queue using an array and perform enqueue at front and display operations.

#include <iostream>
using namespace std;

class Deque {
    int front, rear, size;
    int arr[100];
    
public:
    Deque(int s) { front = rear = -1; size = s; }
    
    void enqueueFront(int value) {
        if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
            cout << "Deque Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = value;
        cout << value << " enqueued at front" << endl;
    }
    
    void display() {
        if (front == -1) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements: ";
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
    Deque dq(5);
    int choice, value;
    
    do {
        cout << "\n1. Enqueue at Front\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue at front: ";
                cin >> value;
                dq.enqueueFront(value);
                break;
            case 2:
                dq.display();
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
