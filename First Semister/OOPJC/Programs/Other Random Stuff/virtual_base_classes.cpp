#include<iostream>
using namespace std;


class Base
{
    public: 
    int i;
};

class D1 : virtual public Base
{
    public: 
    int j;
};


class D2 : virtual public Base
{
    public: 
    int k;
};


class C : public D1, public

D2
{

    public: 
    int l;
    void product()
    {
        return i*j*k;
    }
};

int main()
{
    // usual driver code. 
    return 0;
}