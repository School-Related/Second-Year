// Program for Creating Heaps and Heap Sort
// Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject. Use
// heap data structure and Heap sort.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Heap
{
    vector<int> v;
    int n;
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void heapify(int i)
    {
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l<n && v[l]>v[i])
            largest=l;
        if(r<n && v[r]>v[largest])
            largest=r;
        if(largest!=i)
        {
            swap(v[i],v[largest]);
            heapify(largest);
        }
    }

public:

    Heap()
    {
        n=0;
    }
    void insert(int x)
    {
        v.push_back(x);
        n++;
        int i=n-1;
        while(i>0 && v[parent(i)]<v[i])
        {
            swap(v[i],v[parent(i)]);
            i=parent(i);
        }
    }
    void display()
    {
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    void heapsort()
    {
        for(int i=n-1;i>=0;i--)
        {
            swap(v[0],v[i]);
            n--;
            heapify(0);
        }
    }
    int getmax()
    {
        return v[0];
    }
    int getmin()
    {
        return v[n-1];
    }
    void buildheap()
    {
        for(int i=n/2-1;i>=0;i--)
            heapify(i);
    }
    void swap(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }

};

int main()
{
    Heap h;
    int ch;
    int x;
    do
    {
        cout<<"1.Insert\n2.Display\n3.Heapsort\n4.Get Max\n5.Get Min\n6.Build Heap\n7.Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>x;
            h.insert(x);
            break;
        case 2:
            h.display();
            break;
        case 3:
            h.heapsort();
            break;
        case 4:
            cout<<"Maximum element: "<<h.getmax()<<endl;
            break;
        case 5:
            cout<<"Minimum element: "<<h.getmin()<<endl;
            break;
        case 6:
            h.buildheap();
            break;
        case 7:
            break;
        default:
            cout<<"Invalid Choice\n";
        }
    }while(ch!=7);
    return 0;
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// class Heap
// {
// private:
//     int *arr;
//     int size;

//     void heapify(int i)
//     {
//         int largest = i;
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;

//         if (left < size && arr[left] > arr[largest])
//         {
//             largest = left;
//         }

//         if (right < size && arr[right] > arr[largest])
//         {
//             largest = right;
//         }

//         if (largest != i)
//         {
//             swap(arr[i], arr[largest]);
//             heapify(largest);
//         }
//     }

// public:
//     Heap(int *arr, int n)
//     {
//         this->arr = arr;
//         this->size = n;

//         // build max heap
//         for (int i = n / 2 - 1; i >= 0; i--)
//         {
//             heapify(i);
//         }
//     }

//     void heapSort()
//     {
//         // sort the array using heap sort
//         for (int i = size - 1; i >= 0; i--)
//         {
//             swap(arr[0], arr[i]);
//             size--;
//             heapify(0);
//         }
//     }

//     int getMin()
//     {
//         return arr[0];
//     }

//     int getMax()
//     {
//         return arr[size - 1];
//     }
// };

// int main()
// {
//     // input marks obtained by students
//     int marks[] = {80, 60, 70, 90, 85};

//     // calculate number of students
//     int n = sizeof(marks) / sizeof(marks[0]);

//     // create heap object
//     Heap heap(marks, n);

//     // perform heap sort to find max and min marks
//     heap.heapSort();

//     // print max and min marks
//     cout << "Maximum marks: " << heap.getMax() << endl;
//     cout << "Minimum marks: " << heap.getMin() << endl;

//     return 0;
// }
