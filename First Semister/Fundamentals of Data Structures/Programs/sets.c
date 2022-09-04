#include <stdio.h>
// Defining the 2 Sets

void accept_set(int *set, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &set[i]);
    }
}

void display_set(int *set, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");
}

void find_union(int *set_1, int set_1_size, int *set_2, int set_2_size, int *result, int *size_of_result)
{
    int append = 1, k = 0;
    for (int i = 0; i < set_1_size; i++)
    {
        result[k] = set_1[i];
        k++;
    }

    for (int i = 0; i < set_2_size; i++)
    {
        append = 1;
        for (int j = 0; j < set_1_size; j++)
        {
            if (set_2[i] == result[j])
            {
                append = 0;
                break;
            }
        }

        if (append == 1)
        {
            result[k] = set_2[i];
            k++;
        }
    }
    *size_of_result = k;
}

void find_intersection(int *set_1, int set_1_size, int *set_2, int set_2_size, int *result, int *size_of_result)
{
    int k = 0;
    for (int i = 0; i < set_1_size; i++)
    {
        for (int j = 0; j < set_2_size; j++)
        {
            if (set_1[i] == set_2[j])
            {
                result[k] = set_1[i];
                k++;
            }
        }
    }
    *size_of_result = k;
}

void find_subtracted_set(int *set_1, int set_1_size, int *set_2, int set_2_size, int *result, int *size_of_result)
{
    // Set that has Every element of A that is not in B

    int append = 1, k = 0;

    for (int i = 0; i < set_1_size; i++)
    {
        append = 1;
        for (int j = 0; j < set_2_size; j++)
        {
            if (set_2[j] == set_1[i])
            {
                append = 0;
                break;
            }
        }

        if (append == 1)
        {
            result[k] = set_1[i];
            k++;
        }
    }
    *size_of_result = k;
}

void find_symmetric_set(int *set_1, int set_1_size, int *set_2, int set_2_size, int *result, int *size_of_result)
{
    int union_set_size = set_1_size + set_2_size;
    int intersection_set_size = set_1_size > set_2_size ? set_1_size : set_2_size;

    int union_set[set_1_size + set_2_size];
    int intersection_set[union_set_size];

    find_union(set_1, set_1_size, set_2, set_2_size, union_set, &union_set_size);

    find_intersection(set_1, set_1_size, set_2, set_2_size, intersection_set, &intersection_set_size);

    find_subtracted_set(union_set, union_set_size, intersection_set, intersection_set_size, result, size_of_result);
}

int main()
{
    int set_1[20], set_2[20];
    int result[40];
    int choice = 1, set_1_size = 0, set_2_size = 0;

    printf("Enter the size of the First set\n");
    scanf("%d", &set_1_size);
    accept_set(set_1, set_1_size);

    printf("Enter the size of the second set\n");
    scanf("%d", &set_2_size);
    accept_set(set_2, set_2_size);

    printf("What do you wanna do? \n1. Find union of A and B\n2. Find Intersection of A and B\n3. Find A Symmetric B"
           "\n4. Find A - B\n\n");
    scanf("%d", &choice);

    int size_of_result = set_1_size + set_2_size;

    switch (choice)
    {
    case 1:
        find_union(set_1, set_1_size, set_2, set_2_size, result, &size_of_result);
        printf("The Union of the 2 sets is : \n");
        display_set(result, size_of_result);
        break;
    case 2:
        find_intersection(set_1, set_1_size, set_2, set_2_size, result, &size_of_result);
        printf("The Intersection of the 2 sets is : \n");
        display_set(result, size_of_result);
        break;
    case 3:
        find_symmetric_set(set_1, set_1_size, set_2, set_2_size, result, &size_of_result);
        printf("The Symmetrical set from the 2 sets is : \n");
        display_set(result, size_of_result);
        break;
    case 4:
        find_subtracted_set(set_1, set_1_size, set_2, set_2_size, result, &size_of_result);
        printf("The set A - B is : \n");
        display_set(result, size_of_result);
        break;
    default:
        printf("Try again!\n");
    }

    return 0;
}
