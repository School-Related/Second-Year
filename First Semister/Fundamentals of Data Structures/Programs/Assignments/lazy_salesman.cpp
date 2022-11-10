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
    cin >> t;
    while (t--)
    {
        int number_of_days, min_work, money = 0;
        cin >> number_of_days >> min_work;
        int money_each_day[number_of_days];
        for (int i = 0; i < number_of_days; i++)
        {
            cin >> money_each_day[i];
        }
        insertionSort(money_each_day, number_of_days);
        int i;

        for (i = number_of_days - 1; i >= 0; i--)
        {
            if (money < min_work)
            {
                money += money_each_day[i];
            }
            else{
                break;
            }
        }

        cout << i  + 1<< endl;
        // for (int i = 0; i < number_of_days; i++)
        // {
        //     money -= money_each_day[i];
        //     if (money < min_work)
        //     {
        //         cout << i << endl;
        //         break;
        //     }
        // }
    }
    return 0;
}
