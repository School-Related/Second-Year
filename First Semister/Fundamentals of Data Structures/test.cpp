#include <iostream>
using namespace std;

int f(int x, int n)
{
    if (n == 0)
        return 1;
    else
    {
        return x * f(x, --n);
    }
}

int main()
{
    cout << f(2, 6);
    return 0;
}