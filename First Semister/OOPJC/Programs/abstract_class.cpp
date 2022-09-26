#include<iostream>

using namespace std;


class Employee
{
    virtual int get_salary() = 0;
};

class Developer : public Employee
{
    int salary;

public:
    Developer(int s)
    {
        salary = s;
    }

    int get_salary()
    {
        return salary;
    }
};

class Driver
{
    int salary;
    public: 
    Driver(int t)
    {
        salary = t;
    }

    int get_salary()
    {
        return salary;
    }
};

int main()
{
    Developer d1(5000);
    Driver d2(3000);
    int a, b;
    a = d1.get_salary();
    b = d2.get_salary();

    cout << "Salary of Developer : " << a << endl;
    cout << "Salary of the Driver: " << b << endl;

    return 0;
}