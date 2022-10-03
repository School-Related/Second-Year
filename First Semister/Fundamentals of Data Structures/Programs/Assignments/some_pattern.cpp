#include <iostream>

// 1 2 4 7
// 3 5 8 11
// 6 9 12 14
// 10 13 15 16

using namespace std;

int main()
{
    int t, n, max, temp;
    cin >> t;
    while (t--)
    {
        // Row wise implementation
        cin >> n;
        int arr[n];
        arr[0] = 1;
        temp = n - 1;

        // assigning initial array this the first row. 
        for (int i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] + i;
        }

        // Iterating through that array, and changing its values. 
        for (int i = 1; i < n; i++)
        {
            // This loop will run n number of times, in the process printing the array, and changing it at the same time. 
            for (int j = 0; j < n; j++)
            {
                // Simple Print the element
                cout << arr[j] << " ";

                // Increment that element after printing it to make it ready for the next iteration. 
                if (j < n - 1)
                    arr[j] = arr[j + 1] + 1;
            }
            // The above loop cant alter the last element, coz there is no element after that to increment. 
            // So this will change the last element of our array, depending on the logic.
            arr[n - 1] = arr[n - 2] + temp;
            temp--;

            // End display of first row. 
            cout << endl;
        }

        // Above loop wont print the last row, and so printing the last row here. 
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}