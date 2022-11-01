#include <stdio.h>
#include <stdlib.h>

// Converts a given variable length simple matrix, into a given sparse matrix.
void convert_to_sparse(int *simple_mat, int rows_of_simple, int cols_of_simple, int sparse_mat[][3])
{
    sparse_mat[0][0] = rows_of_simple;
    sparse_mat[0][1] = cols_of_simple;
    int sparse_rows = 1;
    for (int i = 0; i < rows_of_simple; i++)
    {
        for (int j = 0; j < cols_of_simple; j++)
        {
            if (simple_mat[i * rows_of_simple + j] != 0)
            {
                sparse_mat[sparse_rows][0] = i;
                sparse_mat[sparse_rows][1] = j;
                sparse_mat[sparse_rows][2] = simple_mat[i * rows_of_simple + j];
                sparse_rows++;
            }
        }
    }
    sparse_mat[0][2] = sparse_rows - 1;
}

// Simple Transposes the given sparse matrix, and stores the value in the given transpose matrix.
int basic_transpose(int sparse_mat[][3], int transposed_mat[][3])
{
    // Assigning some basic values
    int rows_simple_mat = sparse_mat[0][0];
    int cols_simple_mat = sparse_mat[0][1];
    int no_of_vals = sparse_mat[0][2];

    // Assigning them to the transposed matrix
    transposed_mat[0][0] = cols_simple_mat;
    transposed_mat[0][1] = rows_simple_mat;
    transposed_mat[0][2] = no_of_vals;

    // Error check
    if (no_of_vals == 0)
    {
        printf("Cannot transpose as there are no elements in the matrix\n");
        return 0;
    }

    // counter variable starting from 1 coz 0 is header
    int row_count_t_matrix = 1;

    // transposing
    for (int i = 0; i < cols_simple_mat; i++)
    {
        for (int j = 1; j <= no_of_vals; j++)
        {
            if (sparse_mat[j][1] == i)
            {
                transposed_mat[row_count_t_matrix][0] = sparse_mat[j][1];
                transposed_mat[row_count_t_matrix][1] = sparse_mat[j][0];
                transposed_mat[row_count_t_matrix][2] = sparse_mat[j][2];
                row_count_t_matrix++;
            }
        }
    }
}

// Fast Transposes the given sparse matrix, and stores the value in the given transpose matrix.
void fast_transpose(int sparse_mat[][3], int transponsed_mat[][3])
{
    // Assigning some basic values
    int rows_simple_mat = sparse_mat[0][0];
    int cols_simple_mat = sparse_mat[0][1];
    int no_of_vals = sparse_mat[0][2];

    int transposed_mat[20][3];

    // Assigning them to the transposed matrix
    transposed_mat[0][0] = cols_simple_mat;
    transposed_mat[0][1] = rows_simple_mat;
    transposed_mat[0][2] = no_of_vals;

    // counter variable starting from 1 coz 0 is header
    int row_count_t_matrix = 1;

    for (int i = 0; i <= cols_simple_mat; i++)
    {
        s[i] = 0;
    }
    for (int i = 1; i <= no_of_vals; i++)
    {
        s[a[i][1]]++;
    }

    T[0] = 1;
    for (i = 1; i < cols_simple_mat; i++)
    {
        i = T[a[i][1]];
        b[T[j][0]] = a[i][1];
        b[T[j][1]] = a[i][0];
        b[T[j][2]] = a[i][2];
        T[a[i][1]]++;
    }
}

// Accepts a Variable length 2 Dimensional Matrix
void accept_mat(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i * cols + j]);
        }
    }
}

// Displays a variable length 2 Dimensional Matrix
void display_mat(int *matrix, int rows, int cols)
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int rows_simple = 5, cols_simple = 5, choice = 0;
    int sparse_mat_1_rows = 8;
    int sparse_mat_2_rows = 9;
    int sparse_mat[40][3], transposed_mat[40][3], result_sparse[40][3];

    // defining a simple matrix
    int simple_mat[5][5] = {
        {1, 0, 0, 0, 1},
        {4, 2, 0, 0, 3},
        {0, 0, 0, 0, 4},
        {3, 3, 3, 0, 0},
        {3, 4, 1, 0, 0}};

    // Defining a sparse matrix so we can add it.
    int sparse_mat_1[8][3] = {
        {5, 5, 7},
        {0, 0, 1},
        {0, 0, 4},
        {1, 0, 4},
        {2, 4, 4},
        {3, 2, 3},
        {4, 0, 3},
        {4, 1, 4},
    };

    // Defining another sparse matrix, so we can add it to the previous one.
    int sparse_mat_2[9][3] = {{5, 5, 7},
                              {0, 0, 1},
                              {0, 0, 4},
                              {1, 1, 4},
                              {2, 4, 4},
                              {3, 2, 3},
                              {4, 0, 3},
                              {4, 1, 4},
                              {4, 4, 2}};

    printf("What do you wanna do with the matrices?"
           " \n1. Simple Transpose\n2. Fast Transpose\n\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

        printf("Enter the rows of the Matrix: (Max 5) \n");
        scanf("%d", &rows_simple);
        printf("Enter the columns of the Matrix: (Max 5) \n");
        scanf("%d", &cols_simple);
        pritnf("Enter the simple matrix: \n");
        accept_mat(&simple_mat[0][0], rows_simple, cols_simple);
        printf("The Matrix you entered is: \n\n");
        display_mat(&simple_mat[0][0], rows_simple, cols_simple);
        convert_to_sparse(&simple_mat[0][0], rows_simple, cols_simple, sparse_mat);
        printf("The Sparse Matrix is : \n\n");
        display_mat(&sparse_mat[0][0], sparse_mat[0][2] + 1, 3);
        basic_transpose(sparse_mat, transposed_mat);
        printf("The Transposed Matrix is: \n\n");
        display_mat(&transposed_mat[0][0], transposed_mat[0][2] + 1, 3);
        break;
    case 2:

        printf("Enter the rows of the Matrix: (Max 5) \n");
        scanf("%d", &rows_simple);
        printf("Enter the columns of the Matrix: (Max 5) \n");
        scanf("%d", &cols_simple);

        printf("The Matrix you entered is: \n\n");
        display_mat(&simple_mat[0][0], rows_simple, cols_simple);
        convert_to_sparse(&simple_mat[0][0], rows_simple, cols_simple, sparse_mat);
        printf("The Sparse Matrix is : \n\n");
        display_mat(&sparse_mat[0][0], sparse_mat[0][2] + 1, 3);
        fast_transpose(sparse_mat, transposed_mat);
        printf("The Transposed Matrix is: \n\n");
        display_mat(&transposed_mat[0][0], transposed_mat[0][2] + 1, 3);
        break;
    default:
        printf("Try again\n");
    }

    return 0;
}