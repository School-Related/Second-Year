#include<iostream>

using namespace std;

class Animals
{
    public: 
    virtual void sound()
    {
        cout << "This is a parent class";
    }
};

class Dog
{

    public: 
    virtual void sound()
    {
        cout << "Dogs bark";
    }
    virtual void sight() = 0;
};

int main()
{
    Animals *a;
    Dog *d;
    // a = &d;
    d->sound();
    return 0;
}