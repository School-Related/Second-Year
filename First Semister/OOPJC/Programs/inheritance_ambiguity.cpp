#include<iostream>
using namespace std;

class A
{

    public: 
    void show()
    {
        cout << "Hello from A";
    }
};

class B
{
    public: 
    void show()
    {
        cout << "Hello from B";
    }
};

class C : public A, public B
{   

};

int main()
{
    C c;
    // c.show(); "C: show is ambigious"
    c.A::show(); // would be the syntax to call it.
    c.B::show(); // to call B
    // c.show() // if C had a show method. 
    return 0;
}