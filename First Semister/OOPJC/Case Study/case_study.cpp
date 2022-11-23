// C++ and Java Program to Calculate Average of elements in an Integer Arrays.Take input values.Also display number of elements which are greater than average value.
// Krishnaraj Thadesar
// PA 20 Batch A1

#include <iostream>
using namespace std;
int main()
{
    int size = 10;   
    float average = 0;
    cout << "What size array do you want? " << endl;
    cin >> size;
    float arr[size];
    cout << "Enter the elements of the array!" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        average += arr[i];
    }
    average /= size;
    cout << "The Average of all the elements in the array is: " << average << endl;
    cout << "The Elements of the Array which are greater than the Average of the Array are: " << endl;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > average)
        {
            cout << arr[i] << endl;
            count++;
        }
    }
    cout << endl << "The Number of Elements greater than the Average are: " << count;

    return 0;
}