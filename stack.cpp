#include <iostream>
#include <stack>

using namespace std;

void display(stack<int> s) {
    if (s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack contents (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    int choice, value;

    do {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Push
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:  // Pop
                if (!s.empty()) {
                    s.pop();
                    cout << "Top element popped." << endl;
                } else {
                    cout << "Stack is empty! Cannot pop." << endl;
                }
                break;

            case 3:  // Peek
                if (!s.empty()) {
                    cout << "Top element: " << s.top() << endl;
                } else {
                    cout << "Stack is empty! Cannot peek." << endl;
                }
                break;

            case 4:  // Display
                display(s);
                break;

            case 5:  // Exit
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}