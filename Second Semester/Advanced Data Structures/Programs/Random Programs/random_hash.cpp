#include<iostream>

using namespace std;

int insert_linear_probing_without_replacement(int arr[], int size, int key)
{
    int i = key % size;
    int j = i;
    do
    {
        if (arr[i] == -1)
        {
            arr[i] = key;
            return i;
        }
        else
        {
            i = (i + 1) % size;
        }
    } while (i != j);
    return -1;
}

int main(){
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = -1;
    }
    int key;
    cin >> key;
    int index = insert_linear_probing_without_replacement(arr, 10, key);
    cout << index << endl;
    return 0;
}