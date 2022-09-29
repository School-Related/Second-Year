#include<iostream>

using namespace std;
class space
{
    int x, y, z;
    public: 
    void getdata(int a, int b, int c);
    void display(void);
    void operator-();
};
void space::getdata(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

void space::display()
{
    cout<<"x is "<< x <<endl;
    cout<<"y is "<< y <<endl;
    cout<<"z is "<< z <<endl;

}

void space::operator -()
{
    x = 2*x;
    y = 2*y;
    z = 2*z;
}

int main()
{
    space s;
    s.getdata(10, 20, 30);
    cout<<endl;
    s.display();
    -s;
    cout<<"-S is \n";
    s.display();

    char a[] = "hi asldkfjaslkdj faskl;dfj ";
    int b[] = {1};
    cout<<a<<endl;
    cout<<b;

    return 0;
}