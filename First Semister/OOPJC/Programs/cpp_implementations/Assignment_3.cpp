// Write a C++ program with base class Employee and three derived classes namely
// 1. salaried employees
// 2. commission_employees and
// 3. hourly employees
// Declare calculate_salary() as a pure virtual function in base class and define it in respective
// derived classes to calculate salary of an employee.
// The company wants to implement an Object Oriented Application that performs its payroll
// calculations polymorphically.

// Polymorphism
// Virtual Functionss, overriding functions, and overloading functions.

#include <iostream>
using namespace std;

class Employee
{
public:
    // static int ssn;
    int emp_id = 1000;
    int age = 0;
    double basic_sal = 0, da = 0, ta = 0, gross_sal = 0, net_sal = 0;
    string address_city, position, name;

    virtual void calculate_salary() = 0;

    void display()
    {
        // ssn++;
        // cout << "Employee ssn is:" << ssn << endl;
        cout << "Employee ID is : " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Age: " << age << endl;
        cout << "Employee Address City: " << address_city << endl;
    }

    void accept()
    {
        cout << "Enter the Employee ID: " << endl;
        cin >> emp_id;
        cout << "Enter the Employee Name: " << endl;
        cin >> name;
        cout << "Enter the Employee Age: " << endl;
        cin >> age;
        cout << "Enter the Employee Address City: " << endl;
        cin >> address_city;
    }

    // Destructor
    ~Employee()
    {
        cout << "The Destructor was called" << endl;
    }
};
class SalariedEmployee : public Employee
{
public:
    int weekly_salary;
    int net_sal;
    void accept()
    {
        Employee::accept();
        cout << "Enter the Wage: ";
        cin >> weekly_salary;
    }

    void calculate_salary()
    {
        cout << "Calculating Salary of Salaried Employee" << endl;
        net_sal = weekly_salary * 7;
    }

    void display()
    {
        Employee::display();
        cout << "Weekly Salary is: " << net_sal << endl;
    }
};

class HourlyEmployee : public Employee
{
public:
    int hours, wage;
    int net_sal;

    void accept()
    {
        Employee::accept();
        cout << "Enter the basic salary: " << endl;
        cin >> basic_sal;
        cout << "Enter the Wage: ";
        cin >> wage;
        cout << "Enter the hours worked" << endl;
        cin >> hours;
    }

    void calculate_salary()
    {
        cout << "Calculating Salary of Salaried Employee" << endl;
        if (hours < 40)
        {
            net_sal = basic_sal + hours * wage;
        }
        else
        {
            net_sal = 40 * wage + (hours - 40) * wage * 1.5;
        }
    }

    void display()
    {
        Employee::display();
        cout << "Hourly Employee Salary is: " << net_sal << endl;
    }
};

class CommissionEmployee : public Employee
{
public:
    float gross_sales, commission_rate = 0.05;
    float net_sal;

    void accept()
    {
        Employee::accept();
        cout << "Enter the gross sales: ";
        cin >> gross_sales;
    }

    void calculate_salary()
    {
        cout << "Calculating Salary of Salaried Employee" << endl;
        net_sal = commission_rate * gross_sales;
    }

    void display()
    {
        Employee::display();
        cout << "Commission Employee Salary is: " << net_sal << endl;
    }
};

int main()
{
    cout << "Welcome to Employee Payroll Management System" << endl
         << endl;

    int choice = 1, number = 1;
    Employee *ptr;
    do
    {
        cout << "1. Salaried Employee\n2. Commisisioned Employee\n3. Hourly Employee\n4. Quit\n";
        cout << "\n\nWhose Details do you wanna enter? " << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "How many SalariedEmployees are we talking? ";
            cin >> number;
            SalariedEmployee pr[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Salaried Employee" << endl;
                pr[i].accept();
            }
            cout << "\nHere is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;

            cout << "Salaried Employee" << endl;

            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Salaried Employee " << i + 1 << endl;
                ptr = &pr[i];
                ptr->calculate_salary();
                pr[i].display();
                cout << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "How many Commission Employees are we talking? ";
            cin >> number;
            CommissionEmployee tl[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Commission Employee " << i + 1 << endl;
                tl[i].accept();
            }
            cout << "Here is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;
            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Commission Employee " << i + 1 << endl;
                ptr = &tl[i];
                ptr->calculate_salary();
                tl[i].display();
                cout << endl;
            }
            cout << endl
                 << endl;
        }
        else if (choice == 3)
        {
            cout << "How many Hourly Employees are we talking? ";
            cin >> number;
            HourlyEmployee ap[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Hourly Employees " << i + 1 << endl;
                ap[i].accept();
            }
            cout << "Here is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;
            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Hourly Employees" << i + 1 << endl;
                ptr = &ap[i];
                ptr->calculate_salary();
                ap[i].display();
                cout << endl;
            }
            cout << endl
                 << endl;
        }

    } while (choice != 4);

    return 0;
}