#include <iostream>
using namespace std;
int max_value(int x, int y)
{
    cout << "using function overloading and all" << endl;
    return x > y ? x : y;
}

template <class T>
T max_value(T x, T y)
{
    return x > y ? x : y;
}

template <typename T, class T1> // you can use either of them.
void generic_max_value(T x, T1 x2)
{
    if (x > x2)
    {
        cout << "x is greater";
    }
    else
    {
        cout << "the other variable is greater. ";
    }
}

int main()
{
    int a = 4, b = 0;
    cout << max_value(a, b) << endl; // the one with the defined data type would be preferred over the template one. 
    cout << max_value(0.59, 0.26) << endl;
    generic_max_value(0.59, 26);
    cout << max_value('a', 'b') << endl;
    cout << max_value("something else", "something") << endl;
    return 0;
}