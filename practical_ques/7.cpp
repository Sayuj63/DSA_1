//7. Implement a stack using an array and perform peek and display operations.

#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100];
    
public:
    Stack() { top = -1; }
    
    void push(int value) {
        if (top >= 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack" << endl;
    }
    
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack" << endl;
    }
    
    void peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
    
    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;
    
    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    
    return 0;
}
