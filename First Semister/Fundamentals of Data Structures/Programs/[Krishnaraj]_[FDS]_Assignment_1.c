#include <stdio.h>
#include <stdlib.h>

void print_mat(int mat_1[][20], int i_max, int j_max)
{
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            printf("%d ", mat_1[i][j]);
        }
        printf("\n");
    }
}

void accept_mat(int mat_1[][20], int i_max, int j_max)
{
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            scanf("%d", &mat_1[i][j]);
        }
    }
    
}

void add_mat(int mat_1[][20], int mat_2[][20], int res_mat[][20], int i_max, int j_max)
{
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            res_mat[i][j] = mat_1[i][j] + mat_2[i][j];
        }
    }
}

void sub_mat(int mat_1[][20], int mat_2[][20], int res_mat[][20], int i_max, int j_max)
{
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            res_mat[i][j] = mat_1[i][j] - mat_2[i][j];
        }
    }
}

void multiply_mat(int mat_1[][20], int mat_2[][20], int res_mat[][20], int i_max, int j_max)
{
    for (int k = 0; k < i_max; k++)
    {
        for (int i = 0; i < j_max; i++)
        {
            for (int j = 0; j < j_max; j++)
            {
                res_mat[i][j] += mat_1[i][k] * mat_2[k][j];
            }
        }
    }
}

void transpose(int mat_1[][20], int res_mat[][20], int i_max, int j_max)
{
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j < j_max; j++)
        {
            res_mat[i][j] = mat_1[j][i];
        }
    }
}

int main()
{
    int mat_1[20][20], mat_2[20][20];
    int res_mat[20][20] = {0};


    int m_1_i = 0, m_1_j = 0;
    int m_2_i = 0, m_2_j = 0;

    int choice = 0;

    printf("Enter the size of the First Matrix: \n");
    scanf("%d %d", &m_1_i, &m_1_j);
    printf("Enter the size of the Second Matrix: \n");
    scanf("%d %d", &m_2_i, &m_2_j);

    if (m_1_i != m_2_i || m_1_j != m_2_j)
    {
        printf("The Matrices must have the same number of rows and columns for certain operations. Please Enter Again, \n");
        return 0;
    }
    printf("Enter the Elements of the First Matrix: \n");
    accept_mat(mat_1, m_1_i, m_1_j);
    printf("\n Enter the elements of the second matrix: \n");
    accept_mat(mat_2, m_1_i, m_1_j);

    while (choice != 5)
    {
        printf("What would you like to do? \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_mat(mat_1, mat_2, res_mat, m_1_i, m_1_j);
            printf("\n Result of Addition is: \n");
            print_mat(res_mat, m_1_i, m_1_j);
            break;
        case 2:
            sub_mat(mat_1, mat_2, res_mat, m_1_i, m_1_j);
            printf("\n Result of Subtraction is: \n");
            print_mat(res_mat, m_1_i, m_1_j);
            break;
        case 3:
            multiply_mat(mat_1, mat_2, res_mat, m_1_i, m_1_j);
            printf("\n Result of Multiplication is: \n");
            print_mat(res_mat, m_1_i, m_1_j);
            break;
        case 4:
            transpose(mat_1, res_mat, m_1_i, m_1_j);
            printf("\n Result of  Transpose is: \n");
            print_mat(res_mat, m_1_i, m_1_j);
            break;
        case 5:
            printf("\nThank You!\n");
            break;
        default:
            printf("Enter again, wrong answer");
        }
    }
    return 0;
}