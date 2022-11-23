#include <iostream>
using namespace std;

class Maths
{
public:
    virtual void input() = 0;
    virtual void add() = 0;
    virtual void sub() = 0;
};

class Add : public Maths
{
public:
    int a, b, c;

    void input()
    {
        cout << "Enter two numbers:";
        cin >> a >> b;
    }

    void add()
    {
        c = a + b;
        cout << "Sum is:" << c;
    }
    void sub()
    {
        cout << "not using here";
    }
};

class Sub : public Maths
{
public:
    int a, b, c;

    void input()
    {
        cout << "Enter two numbers:";
        cin >> a >> b;
    }

    void sub()
    {
        c = a - b;
        cout << "differencr is:" << c;
    }
    void add()
    {
        cout << "not using here";
    }
};

int main()
{
    Maths *m;
    Add d;
    Sub s;
    m = &d;
    m->input();
    m->add();
    m = &s;
    m->input();
    m->sub();
    return 0;
}