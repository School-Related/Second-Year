// Create a C++ program that creates a class "Arithmatic" which contains integer data members. Overload all the four arthmetic operators so that they operate on the objects of "Arthmatic".

#include <iostream>
using namespace std;

class Arithmatic
{
public:
    int x, y;
    Arithmatic(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }

    Arithmatic operator+(Arithmatic const &obj)
    {
        Arithmatic res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        return res;
    }
    Arithmatic operator-(Arithmatic const &obj)
    {
        Arithmatic res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        return res;
    }
    Arithmatic operator/(Arithmatic const &obj)
    {
        Arithmatic res;
        res.x = x / obj.x;
        res.y = y / obj.y;
        return res;
    }
    Arithmatic operator*(Arithmatic const &obj)
    {
        Arithmatic res;
        res.x = x * obj.x;
        res.y = y * obj.y;
        return res;
    }
    void print()
    {
        cout << x << endl;
        cout << y << endl;
    }
};

int main()
{
    Arithmatic a(1, 2), b(2, 3);
    Arithmatic res;
    res = a + b;
    res.print();
    res = a - b;
    res.print();
    res = a / b;
    res.print();
    res = a * b;
    res.print();
    return 0;
}
