#include<iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}


int main()
{
    int a = 2, b = 3;
    int c;
    // cout << add(2, 3);

    // if(add(1, 2) == 3)
    // {
    //     cout << "Yup" << endl;
    // }

    // cout << "Enter a number" << endl;
    // cin >> a;
    // if(a == 65)
    // {
    //     cout << "you entered a";
    // }
    cout << "Enter some stuff" << endl;
    cin >> a >> b;
    c = a / b;
    cout << c;

    return 0;
}