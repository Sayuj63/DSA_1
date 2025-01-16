#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int number;
    cout << "Enter the number to be searched: ";
    cin >> number;
    
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == number)
        {
            cout << "Element found at index " << i << endl;
            return 0;
        }
       
    }

}
