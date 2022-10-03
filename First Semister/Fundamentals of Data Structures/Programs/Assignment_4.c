#include <stdio.h>

void accept(int arr[], int size)
{
    printf("\nAccepting the Array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int size)
{
    printf("\nDisplaying the Array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int find_max(int arr[], int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void bucket_sort_integers(int arr[], int size)
{
    int i, j;
    int max = find_max(arr, size) + 1;
    int bucket[max];
    // declaring bucket values to 0
    for (int i = 0; i < max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        bucket[arr[i]]++; // incrementing the values of bucket for each respective value of arr
    }
    for (int i = 0, j = 0; i < max; i++)
    {
        for (; bucket[i] > 0; bucket[i]--)
        {
            arr[j] = i;
            j++;
        }
    }
}

// Doesnt work
void radix_sort(int arr[], int size)
{
    int large, pass, div, bktno, count[10], bkt[20][20];
    large = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    int passes = 0;
    while (large > 0)
    {
        passes++;
        large = large / 10;
        div = 1;
        for (int i = 0; i <= passes; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                count[i] = 0;
            }
            for (int j = 0; j < size; j++)
            {
                bktno = (arr[i] / div) % 10;
                bkt[bktno][count[bktno]] = arr[j];
                count[bktno]++;
            }
            int j = 0;
            for (bktno = 0; bktno <= 9; bktno++)
            {
                for (int k = 0; k < count[bktno]; k++)
                {
                    arr[j] = bkt[bktno][k];
                    j++;
                }
            }
            div = div * 10;
        }
    }
}

int main()
{
    int arr[10] = {9, 0, 8, 8, 1, 4, 3, 1, 4, 7};
    int arrf[10] = {9.23, 0.35, 8.95, 8.86, 1.50, 4.22, 4.96, 1.00, 4.55, 7.2};

    int size = 10;
    int sizef = 10;

    printf("Enter the size of the Array : \n");
    scanf("%d", &size);
    // accept(arr, size);
    display(arr, size);
    bucket_sort_integers(arr, size);
    radix_sort(arrf, sizef);
    display(arr, size);
    return 0;
}