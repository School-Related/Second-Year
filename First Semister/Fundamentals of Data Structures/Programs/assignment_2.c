#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linear search, binary search, selection sort, insertion sort, shell sort.

struct Student
{
    int roll_no;
    char name[100];
    int marks;
};

void accept_array(struct Student students[], int number_of_students)
{
    for (int i = 0; i < number_of_students; i++)
    {
        printf("Enter the roll number : ");
        scanf("%d", &students[i].roll_no);
        printf("\nEnter the Name: ");
        scanf("%s", students[i].name);
        printf("Enter the marks");
        scanf("%d", &students[i].marks);
        printf("\n");
    }
}

void display(struct Student students[], int number_of_students, int i)
{

    printf("--------------------------\n");
    printf("|\tNo|\tName|\tMarks|\n");
    for (; i < number_of_students; i++)
    {
        printf("|\t%d|\t%s|\t%d|\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    printf("---------------------------\n");
}

void swap(struct Student *a, struct Student *b)
{
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}


int linear_search(struct Student students[], int number_of_students, int key)
{
    int linear_search_result_key = 0; // 1
    int count = 0;                    // 1
    if (key < 0)                      // 1
    {
        return -1;
    }
    for (int i = 0; i < number_of_students; i++) // n+1
    {
        count++;
        if (key == students[i].roll_no)
        {
            return i;
        }
    }
    if (count >= number_of_students) // 1
    {
        return -1;
    } // n + 5
} // time complexity is O(n)

int binary_search_iterative(struct Student students[], int number_of_students, int key)
{
    int low = 0;
    int high = number_of_students - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (students[mid].roll_no == key)
        {
            return mid;
        }
        else if (students[mid].roll_no > key)
        {
            high = mid - 1;
        }
        else if (students[mid].roll_no < key)
        {
            low = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(struct Student students[], int number_of_students, int low, int high, int key)
{
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (students[mid].roll_no == key)
        {
            return mid;
        }
        else if (students[mid].roll_no > key)
        {
            return binary_search_recursive(students, number_of_students, low, mid - 1, key);
        }
        else if (students[mid].roll_no < key)
        {
            return binary_search_recursive(students, number_of_students, mid + 1, high, key);
        }
    }
    return -1;
}

int selection_sort(struct Student students[], int number_of_students)
{
    int min;
    for (int i = 0; i < number_of_students - 1; i++)
    {
        // assign the minimum element equal to i
        min = i;
        // find the minimum element in the rest of the array
        for (int j = i + 1; j < number_of_students; j++)
        {
            if (students[j].marks > min)
            {
                min = j;
            }
        }

        // swap with the first element, coz its min.
        if (min != i)
        {
            swap(&students[i], &students[min]);
            // swap(students, i, min);
        }
    }
}

int insertion_sort(struct Student students[], int number_of_students)
{
    int j, key;
    for (int i = 0; i < number_of_students; i++)
    {
        key = students[i].marks;
        j = i - 1;
        while (j >= 0 && students[j].marks > key)
        {
            swap(&students[j + 1], &students[j]);
            j--;
        }
    }
}

int shell_sort(struct Student students[], int number_of_students)
{
}

int main()
{
    int choice = 0;
    int linear_search_key = 0, linear_search_result_key = 0, binary_search_key = 0, binary_search_result_key = 0;
    int number_of_students = 3;
    struct Student students[3] =
        {
            {1, "a", 90},
            {2, "b", 100},
            {3, "c", 70}};

    // accept_array(students, number_of_students);
    display(students, 3, 0);

    printf("\n\n Welcome to Assignment 2\n");
    printf("What do you want to do? \n");
    printf("1. Linear Search an element\n2. Binary Search (Iterative) an Element\n3. Binary Search (Recursive)\n4. Sort with Selection Sort\n5. Sort with Insertion Sort\n6. Sort with Shell Sort\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter The Roll number of the student : ");
        scanf("%d", &linear_search_key);
        linear_search_result_key = linear_search(students, 3, linear_search_key);
        if (linear_search_result_key < 0)
        {
            printf("\nRecords not found!\n");
        }
        else
        {
            linear_search_result_key++;
            printf("The Key was found at position : %d", linear_search_result_key);
            display(students, linear_search_result_key, linear_search_result_key - 1);
        }
        printf("\n");
        break;
    case 2:
        printf("Enter The Roll number of the student : ");
        scanf("%d", &binary_search_key);
        binary_search_result_key = binary_search_iterative(students, number_of_students, binary_search_key);
        if (binary_search_result_key < 0)
        {
            printf("\nRecords not found!\n");
        }
        else
        {
            binary_search_result_key++;
            printf("The Key was found at position : %d", binary_search_result_key);
            printf("\n");
            display(students, binary_search_result_key, binary_search_result_key - 1);
        }
        printf("\n");
        break;
    case 3:
        printf("Enter The Roll number of the student : ");
        scanf("%d", &binary_search_key);
        binary_search_result_key = binary_search_recursive(students, number_of_students, 0, number_of_students - 1, binary_search_key);
        if (binary_search_result_key < 0)
        {
            printf("\nRecords not found!\n");
        }
        else
        {
            binary_search_result_key++;
            printf("The Key was found at position : %d", binary_search_result_key);
            printf("\n");
            display(students, binary_search_result_key, binary_search_result_key - 1);
        }
        printf("\n");
        break;

    case 4:
        printf("\nHere are the Students sorted by their marks with selection sort\n");
        selection_sort(students, number_of_students);
        display(students, number_of_students, 0);
        break;
    
    case 5:
        printf("\nHere are the Students sorted by their marks with insertion sort\n");
        insertion_sort(students, number_of_students);
        display(students, number_of_students, 0);
        break;
    default:
        printf("\nWrong value entered. \n");
        break;
    }

    return 0;
}