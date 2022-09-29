#include <iostream>
using namespace std;

// class a
// {
//     public:
//     a()
//     {
//         cout << "\n Base Construcotr";
//     }
//     virtual ~a()
//     {
//         cout << "Base class des";
//     }
// };

// class b : public a
// {
// public:
//     b()
//     {
//         cout << "derived cons";
//     }

//     ~b()
//     {
//         cout << "derived des";
//     }
// };

class A
{
public:
    A()
    {
        cout << "constructor" << endl;
    }
    ~A()
    {
        cout << "Destructor" << endl;
    }
};

int main()
{
    A obj;

    // a *obj = new b;
    // delete obj;

    // b obje;

    return 0;
}