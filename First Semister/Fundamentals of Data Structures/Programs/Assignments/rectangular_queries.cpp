#include <iostream>

using namespace std;

int count_distinct(int some_arr[], int size)
{
    int distinct = 0;
    int count = 0;
    // int random_arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     random_arr[i] = some_arr[i];
    // }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((some_arr[i] == some_arr[j]) && some_arr[j] != -1)
            {
                count++;
                some_arr[j] = -1;
            }
        }
    }

    distinct = size - count;
    return distinct;
}

int main()
{

    int t, n, q, distinct_elements = 0;
    int x1, y1, x2, y2;
    cin >> n;
    int arr[n][n];
    int subarr[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> q;
    while (q--)
    {
        // Taking in max and min limits.
        cin >> x1 >> y1 >> x2 >> y2;
        distinct_elements = 0;
        int k = 0;

        // Reducing 1 so as to match common sense.
        x1--;
        x2--;
        y1--;
        y2--;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl
        //      << endl
        //      << endl;

        // Calculate distinct elements
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                // cout << arr[i][j] << " ";
                subarr[k] = arr[i][j];
                k++;
            }
            // cout << endl;
        }
        cout << count_distinct(subarr, k) << endl;

        
        for (int i = 0; i < n; i++)
        {
            subarr[i] = 0;
        }
    }
}