// program for heap implementation using array
// Author: Krishnaraj Thadesar
// ADS Assignment 7 
// Heap Sort and Heapify


#include <iostream>
using namespace std;

class Heap
{
private:
    int *arr;
    int size;

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    Heap(int *arr, int n)
    {
        this->arr = arr;
        this->size = n;

        // build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapSort()
    {
        int size = this->size;
        // sort the array using heap sort
        for (int i = size - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            size--;
            heapify(0);
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int getmax()
    {
        return arr[0];
    }
};

int main()
{
    int no_of_marks;
    cout << "Welcome to ADS Assignment 7" << endl;
    cout << "Enter the number of marks: ";
    cin >> no_of_marks;

    int marks[no_of_marks];
    cout << "Enter the marks: ";
    for (int i = 0; i < no_of_marks; i++)
    {
        cin >> marks[i];
    }

    Heap MarksHeap(marks, no_of_marks);

    cout << "The maximum marks are: " << MarksHeap.getmax() << endl;

    cout << "The sorted marks are: " << endl;
    MarksHeap.heapSort();

    MarksHeap.print();

    return 0;
}