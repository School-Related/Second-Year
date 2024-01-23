#include <stdio.h>

// Bankers Algorithm
int allocation[5][3] = {
    {0, 1, 0},
    {3, 0, 2},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}};
int max[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}};
int available[5][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};
int need[5][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

int work[3] = {0, 0, 0};
int max_resources[3] = {10, 5, 7};
int finish[5] = {0, 0, 0, 0, 0};
void calc_work()
{
    int temp = 0;
    for (int j = 0; j < 3; j++)
    {
        temp = 0;
        for (int i = 0; i < 5; i++)
        {
            temp += allocation[i][j];
        }
        work[j] = max_resources[j] - temp;
    }
}

void calc_need()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            need[j][i] += max[j][i] - allocation[j][i];
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

int checkFinish()
{
    for (int i = 0; i < 5; i++)
    {
        if (finish[i] < 1)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int t = 0;
    int request[3] = {0, 0, 0};
    calc_work();
    calc_need();
    printf("At what time instant do you want some random process to need some resources? \n");
    scanf("%d", &t);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("The need matrix is: \n");
    display_mat(&need[0][0], 5, 3);
    printf("\nThe Safe State is: \n");
    int block = 0;
    do
    {
        for (int j = 0; j < 5; j++)
        {
            if (t == j + 1 && block != 1)
            {
                if (request[0] <= work[0] && request[1] <= work[1] && request[2] <= work[2])
                {
                    work[0] -= request[0];
                    work[1] -= request[1];
                    work[2] -= request[2];
                    block = 1;
                }
            }
            if (!finish[j])
            {
                if (need[j][0] <= work[0] && need[j][1] <= work[1] && need[j][2] <= work[2])
                {
                    finish[j] = 1;
                    printf(" %d ", j);
                    work[0] += allocation[j][0];
                    work[1] += allocation[j][1];
                    work[2] += allocation[j][2];
                }
            }
        }
    } while (!checkFinish());

    return 0;
}