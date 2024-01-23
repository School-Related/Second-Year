#include <iostream>
#include<typeinfo>
using namespace std;

int add(int a, int b)
{
    if(a < 0)
    {
        throw 'w';
    }
    return a + b;
}

int main()
{

    int a, b, c;
    cout << "Enter some stuff" << endl;
    cin >> a >> b;
    try
    {
        // cout << typeid(a).name() << endl;
        // if(typeof(a) == char)
        // cout << isdigit(a) << endl;
        // if (!isdigit(a) && !isdigit(b))
        // {
        //     cout << "It is a digit";
        // }

        add(a, b);

        if (b != 0)
            c = a / b;
        else
            throw(b);
        cout << c;
    }
    catch(int i)
    {
        cout << "You cant divide by Zero man" << endl;
    }
    catch (char a)
    {
        cout << "some char";
    }
    return 0;
}
