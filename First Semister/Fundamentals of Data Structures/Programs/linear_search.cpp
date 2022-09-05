// Program to implement linear search

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Key found at position: " << i + 1 << endl;
            return 0;
        }
    }
    cout << "Key not found" << endl;
    return 0;
}