#include <stdio.h>

// using namespace std;

int main()
{

    int t, n, q, distinct_elements = 0;
    int x1, y1, x2, y2;
    int count = 0;
    int bucket[11];
    scanf("%d", &n);
    int arr[n][n];
    int subarr[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        // Taking in max and min limits.
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        distinct_elements = 0;
        count = 0;

        // Reducing 1 so as to match common sense.
        x1--;
        x2--;
        y1--;
        y2--;

        for (int i = 0; i < 11; i++)
        {
            bucket[i] = 0;
        }

        // Calculate distinct elements
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                bucket[arr[i][j]]++;
                if (bucket[arr[i][j]] == 2)
                    count++;
                if (count == 10)
                {
                    printf("10\n");
                    break;
                }
            }
            if (count == 10)
                break;
        }
        if (count == 10)
            continue;
        for (int i = 1; i < 11; i++)
        {
            if (bucket[i] != 0)
            {
                distinct_elements++;
            }
        }
        printf("%d\n", distinct_elements);
    }
}