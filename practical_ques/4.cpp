//4. Write a program to sort an array in descending order using insertion sort.

#include <iostream>
using namespace std;

void insertionSortDescending(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {50, 20, 40, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    insertionSortDescending(arr, size);
    
    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
