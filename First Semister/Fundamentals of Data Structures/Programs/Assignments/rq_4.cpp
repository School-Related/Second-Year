#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, q, distinct_elements = 0;
    int x1, y1, x2, y2;
    int bucket[11];
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

        unordered_set<int> s;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                if (!s.count(arr[i][j])) // <--- avg O(1) time
                {
                    s.insert(arr[i][j]);
                }
            }
            if (s.size() == 10)
                break;
        }

        if (s.size() == 10)
        {
            cout << s.size() << endl;
            continue;
        }
        cout << s.size() << endl;
        distinct_elements = 0;
    }
}