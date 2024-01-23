#include <iostream>
using namespace std;

int main()
{
    int t, n;
    int min = 0, max = 0;
    cin >> t;
    while (t--)
    {
        int count = 1;
        max = 0;
        cin >> n;
        min = n;
        // Defining 2 Arrays
        int arr[n], distances[n];

        // The distance of the last element from the element right of it is obviously greater than 2
        distances[n - 1] = 3;

        // Input the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // calculate distance array which is distance between 2 adjacent arrays
        for (int i = 0; i < n - 1; i++)
        {
            distances[i] = arr[i + 1] - arr[i];
        }

        // Iterate through the distance array
        for (int i = 0; i < n; i++)
        {
            // If distance is less than, or equal to 2, then increase count, which is the number of people who are going to get infected.
            if (distances[i] <= 2)
            {
                count++;
            }

            // If its the last element, or if the distances are greater than 2, which means, the number of people who would get infected are now
            // safely out of reach of the next element, then we can assign the value of max to the value of count in that group, or min, depending
            // on the value of count.
            if (i == n - 1 || distances[i] > 2)
            {
                if (count > max)
                    max = count;
                if (count < min)
                    min = count;
                count = 1;
            }
        }
        cout << min << " " << max << endl;
    }
}