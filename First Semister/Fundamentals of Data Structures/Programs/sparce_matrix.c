#include <stdio.h>
#include <stdlib.h>

void convert_to_sparse(int simple_mat[][5], int sparse_mat[][3], int rows, int cols)
{
    sparse_mat[0][0] = rows;
    sparse_mat[0][1] = cols;
    int sparce_rows = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (simple_mat[i][j] != 0)
            {
                sparse_mat[sparce_rows][0] = i;
                sparse_mat[sparce_rows][1] = j;
                sparse_mat[sparce_rows][2] = simple_mat[i][j];
                sparce_rows++;
            }
        }
    }
    sparse_mat[0][2] = sparce_rows - 1;

    printf("Here is the Compact matrix\n\n");

    for (int i = 0; i < sparce_rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sparse_mat[i][j]);
        }
        printf("\n");
    }
}

int basic_transpose(int sparse_mat[][3], int transposed_mat[][3], int rows, int cols)
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
        return 0;

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

    printf("Here is the transposed matrix\n\n");

    for (int i = 0; i < row_count_t_matrix; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transposed_mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void accept_mat(int simple_mat[][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &simple_mat[i][j]);
        }
    }
}

void display_mat(int simple_mat[][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", simple_mat[i][j]);
        }
        printf("\n");
    }
    printf("\ndone");
}

int main()
{
    int rows = 5, cols = 5;
    int simple_mat[5][5] = {
        {1, 0, 0, 0, 1},
        {4, 2, 0, 0, 3},
        {0, 0, 0, 0, 4},
        {3, 3, 3, 0, 0},
        {3, 4, 1, 0, 0}};

    int sparse_mat[20][3] = {0};
    int transposed_sparse_mat[20][3] = {7};
    // printf("Enter the rows of the Matrix: \n");
    // scanf("%d", &rows);
    // printf("Enter the columns of the Matrix: \n");
    // scanf("%d", &cols);
    display_mat(simple_mat, rows, cols);
    printf("Converting to sparse matrix\n");
    convert_to_sparse(simple_mat, sparse_mat, rows, cols);
    basic_transpose(sparse_mat, transposed_sparse_mat, rows, cols);
    // display_mat(sparse_mat, 20, 3);
    return 0;
}