// write a program explaining the concept of pointers in C++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a;
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value using pointer: " << *ptr << endl;
    cout << "Address stored in pointer: " << ptr << endl;
    
    *ptr = 20;
    cout << "Updated value of a: " << a << endl;
    
    int b = 30;
    ptr = &b;
    cout << "New value using pointer: " << *ptr << endl;

    return 0;
}
