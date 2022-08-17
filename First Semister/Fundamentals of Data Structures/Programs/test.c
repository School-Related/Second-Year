#include <stdio.h>
#include <stdlib.h>

void accept(int a[10][10], int m, int n);
void display(int a[10][10], int m, int n);
void addition(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n);
void subtraction(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n);
void multiplication(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n, int m2);
void transpose(int M1[10][10], int M3[10][10], int m, int n);

int main()
{
    int M1[10][10], M2[10][10], M3[10][10], m1, n1, m2, n2;
    printf("\n Enter the size of first matrix");
    scanf("%d %d", &m1, &n1);
    printf("\nenter the elments of first matrix");
    accept(M1, m1, n1);
    display(M1, m1, n1);

    printf("\n Enter the size of second matrix");
    scanf("%d %d", &m2, &n2);
    printf("\nenter the elments of second matrix");
    accept(M2, m2, n2);
    display(M2, m2, n2);
    int choice;
    for (;;)
    {
        printf("\n MENU");
        printf("\n1. Addition of two matrices");
        printf("\n2. Subtraction of two matrices");
        printf("\n3. Multiplication of two matrices");
        printf("\n4. Transpose of  matrix");
        printf("\n5. Exit");
        printf("\nEnter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addition(M1, M2, M3, m1, n1);
            display(M3, m1, n1);
            break;
        case 2:
            subtraction(M1, M2, M3, m1, n1);
            display(M3, m1, n1);
            break;
        case 3:
            multiplication(M1, M2, M3, m1, n1, m2);
            display(M3, m1, n1);
            break;
        case 4:
            transpose(M1, M3, m1, n1);
            display(M3, m1, n1);
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}

void accept(int a[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void display(int a[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", &a[i][j]);
        printf("\n");
    }
}

void addition(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M3[i][j] = M1[i][j] + M2[i][j];
}

void subtraction(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M3[i][j] = M1[i][j] - M2[i][j];
}

void multiplication(int M1[10][10], int M2[10][10], int M3[10][10], int m, int n, int m2)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M3[i][j] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m2; k++)
                M3[i][j] += M1[i][j] * M2[i][j];
}

void transpose(int M1[10][10], int M3[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            M3[i][j] = M1[i][j];
}