#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int t = 0;
    int number_of_students = 0, number_of_books = 0;

    cin >> t;
    while (t--)
    {
        cin >> number_of_students >> number_of_books;
        int books[number_of_books], count[number_of_students], page_count[number_of_students];
        int students_l[number_of_students];
        int students_u[number_of_students];
        for (int i = 0; i < number_of_books; i++)
        {
            cin >> books[i];
        }
        for (int i = 0; i < number_of_students; i++)
        {
            cin >> students_l[i];
        }
        for (int i = 0; i < number_of_students; i++)
        {
            cin >> students_u[i];
        }
        insertionSort(books, number_of_books);
        for (int j = 0; j < number_of_students; j++)
        {
            count[j] = 0;
            page_count[j] = 0;
            for (int i = 0; i < number_of_books; i++)
            {
                if (students_l[j] < books[i] && students_u[j] > books[i])
                {
                    count[j]++;
                    page_count[j] += books[i];
                }
            }
        }
        for (int i = 0; i < number_of_students; i++)
        {
            cout << count[i] << " " << page_count[i] << endl;
        }
    }
    return 0;
}