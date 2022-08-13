#include <iostream>
using namespace std;
class Employee
{
private:
    int emp_id = 1234;
    static int ssn;

public:
    // Default Constructor
    Employee()
    {
        ssn += 1;
        cout << "The Default Constructor was called" << endl;
    }

    // Parameterized Constructor
    Employee(int e_id)
    {
        cout << "Parameterized constructor was called";
        emp_id = e_id;
    }

    // Copy Constructor
    Employee(Employee &E)
    {
        cout << "Copy Constructor was called" << endl;
        emp_id = E.emp_id;
    }

    void display()
    {
        cout << "The Employee ID is : " << emp_id << endl;
        cout << "The Employee ssn is:" << ssn << endl;
    }

    void accept()
    {
        cout << "Enter the Employee ID" << endl;
        cin >> emp_id;
    }

    // Destructor
    ~Employee()
    {
        cout << "The Destructor was called" << endl;
    }
};

int Employee::ssn;

int main()
{
    static int count = 0;
    cout << "How many values do you wanna input ?";
    cin >> count;

    // Employee Obj[count];
    Employee *Obj = new Employee[count];
    cout << "Enter the Details" << endl;

    for (int i = 0; i < count; i++)
    {
        Obj[i].accept();
    }
    for (int i = 0; i < count; i++)
    {
        Obj[i].display();
    }

    delete[] Obj;
    return 0;
}
