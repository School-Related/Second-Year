#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[10] = {10, 20, 22, 26, 89, 90, 99, 100, 120, 0};
    printf("%d", arr[3]);
    int pos = -1;
    int i = 0;
    int key = 25;
    int n = 9;
    while (arr[i++] <= key)
    {
    }
    pos = i - 1;
    for (int k = n - 1; k >= pos; k--)
    {
        int temp = arr[k + 1];
        arr[k + 1] = arr[k];
        arr[k] = temp;
    }
    arr[pos] = key;
    printf("%d", arr[3]);

    return 0;
}
