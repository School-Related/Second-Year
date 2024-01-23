#include <iostream>

using namespace std;

long int find_sum(long int arr[], int begin, int end)
{
    long int sum = 0;
    for (int i = begin; i < end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

long int find_prod(long int arr[], int begin, int end)
{
    long int prod = 1;
    for (int i = begin; i < end; i++)
    {
        prod *= arr[i];
    }
    return prod;
}

int main()
{
    long int t, n, count = 0, temp;
    cin >> t;
    while (t--)
    {
        count = 0;
        cin >> n;
        long int arr[n];

        // Taking the Array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (find_sum(arr, j, i + 1) == find_prod(arr, j, i + 1))
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}