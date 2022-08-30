#include<iostream>
using namespace std;

// Algorithm for Saddle Point

// 1. Find the minimum element in the matrix
// 2. Find the maximum element in the matrix
// 3. If the minimum element is equal to the maximum element, then the matrix has a saddle point


// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     int a[m][n];
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     int min = a[0][0];
//     int max = a[0][0];
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (a[i][j] < min)
//                 min = a[i][j];
//             if (a[i][j] > max)
//                 max = a[i][j];
//         }
//     }
//     if (min == max)
//         cout << "Saddle Point exists";
//     else
//         cout << "Saddle Point does not exist";
//     return 0;
// }

// int sad_i = -1, sad_j = -1;
// int find_max(int arr[], int size)
// {
//     int max = 0;
//     for (int i = 0; i < size;i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

int find_min(int arr[], int size)
{
    int min = 5000;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int find_sad(int arr[][3], int row_size, int col_size, int *sad_i, int *sad_j)
{
    int rows[row_size], cols[col_size];
    int col_max, row_min;
    int row_i, row_j;


    // find the max of each column and append to cols
    for (int i = 0; i < 0;i++)
    {
        rows[i] = find_max(arr[i], row_size);
    }

    // find the minimum value of the row
    row_min = find_min(rows, row_size);

    int temp[row_size];
    // find the max of each column and append to cols
    for (int j = 0; j < col_max; j++)
    {
        for (int i = 0; i < row_size; i++)
        {
            temp[j] = arr[i][j];
        }
        cols[j] = find_min(temp, col_size);
    }

    // for (int i = 0; i < row_size; i++)
    // {
    //     rows[i] = find_max(arr[i], row_size);
    //     for (int j = 0; j < col_size; j++)
    //     {
    //         temp[j] = arr[i][j];
    //     }
    //     cols[col] = find_max(temp, col_size);
    //     col++;
    // }




    // find the min of rows
    row_min = find_min(rows, row_size, &row_i);
    // find the max of cols
    col_max = find_max(cols, col_size, &row_j);
    // check if they are same, and return the result.

    if(row_min != col_max)
    {
        return -1;
    }
    else 
    {
        *sad_i = row_i;
        *sad_j = row_j;
    }
}

int main()
{
    int sad_point = 0;
    int arr[3][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {5, 5, 5}};

    sad_point= find_sad(arr, 3, 3);

    if(sad_i  < 0 || sad_j < 0)
    {
        cout << "The Saddle point does not exist";
    }

    cout << "The Saddle Point is: " << sad_point;
    cout << "The Values of I and j for the Saddle point are: " << sad_i << " and " << sad_j;
    return 0;
}