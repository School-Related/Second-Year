#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n, q;
    cin >> n;
    cin >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    while (q--)
    {
        int op = 0, lower = 0, upper = 0, count = 0;
        cin >> op >> lower >> upper;
        if (op == 1)
        {
            for (int i = lower; i <= upper; i++)
            {
                if (arr[i] % 3 == 0)
                {
                    count++;
                }
            }
            cout << count << endl;
        }
        else if (op == 0)
        {
            for (int i = lower; i <= upper; i++)
            {
                arr[i] += 1;
            }
        }
    }
    return 0;
}
