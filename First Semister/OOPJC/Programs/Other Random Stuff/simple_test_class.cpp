#include <iostream>

using namespace std;

class parent
{
private:
    int a = 45;

protected:
    int b = 1;

public:
    int c = 3;

    parent()
    {
        cout << "The constructor of the parent is called. " << endl;
    }

    void printsum()
    {
        cout << a + b;
    }

    void bubble_sort(int arr[], int size)
    {
        int temp = 0;
        // first for loop
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display(int arr[], int size)
    {
        for (int j = 0; j < size; j++)
            cout << arr[j] << " ";
    }
};



class child : public parent
{
    public: 
    child()
    {
        cout << "The constructor of the child is called" << endl;
    }
    // private:
    //     int a = 45;
    //     int b = 1;
    //     int c = 3;

    //     void printsum()
    //     {
    //         cout << a + b;
    //     }
    protected:
        int dd = 0;

    public:
        void print()
        {
            printsum();
            cout << b + c;
    }
};




int main()
{
    // parent obj;
    child child_obj;
    // obj.printsum();
    // some_object.print();
    int arr[5] = {5, 4, 3, 2, 1};
    // some_object.b;
    // some_object.dd;




    // obj.bubble_sort(arr, 5);
    // obj.display(arr, 5);
    return 0;
}