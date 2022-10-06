/* CPP program to print all distinct elements
of a given array */
#include <bits/stdc++.h>
using namespace std;

// This function prints all distinct elements
void printDistinct(int arr[], int n)
{
    // Creates an empty hashset
    unordered_set<int> s;

    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // if element is not present then s.count(element) return 0 else return 1
        // hashtable and print it
        if (!s.count(arr[i])) // <--- avg O(1) time
        {
            s.insert(arr[i]);
            cout << arr[i] << " ";
        }
    }
}

// Driver method to test above method
int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = 7;
    printDistinct(arr, n);
    return 0;
}
