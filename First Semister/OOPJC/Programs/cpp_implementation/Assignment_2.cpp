#include <iostream>
using namespace std;

class Employee
{

protected:
    static int ssn;
    int emp_id = 1000;
    int age = 0;
    double basic_sal = 0, da = 0, ta = 0, gross_sal = 0, net_sal = 0;
    string address_city, position, name;

public:
    // Default Constructor
    Employee()
    {
        cout << "The Default Constructor was called" << endl;
    }

    // Parameterized Constructor
    Employee(int e, int a, string add, string nam)
    {
        cout << "Parameterized constructor was called\n";
        emp_id = e;
        age = a;
        address_city = add;
        name = nam;
    }

    // Copy Constructor
    Employee(Employee &E)
    {
        cout << "Copy Constructor was called" << endl;
        emp_id = E.emp_id;
        age = E.age;
        address_city = E.address_city;
        name = E.name;
    }

    void display()
    {
        Employee::ssn++;
        cout << "Employee ssn is:" << ssn << endl;
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

int Employee::ssn = 1000;

class Programmer : public Employee
{

protected:
    double da = 0, hra = 0, pf = 0, scf = 0;

public:
    void calc_gross_sal()
    {
        da = 0.97 * basic_sal;
        hra = basic_sal;
        pf = basic_sal;
        scf = basic_sal;
        gross_sal = da + hra + pf + scf + basic_sal;
    }

    void calc_net_sal()
    {
        // Reducing Income Taxes
        net_sal = gross_sal - (0.15) * gross_sal;
    }

    void accept()
    {
        Employee::accept();
        cout << "Enter the basic Salary of the Programmer : " << endl;
        cin >> basic_sal;
        calc_gross_sal();
        calc_net_sal();
    }

    void display()
    {
        Employee::display();
        cout << "The Gross Salary is: " << gross_sal << endl;
        cout << "The Net Salary is: " << net_sal << endl;
    }
};

class TeamLeader : public Employee
{

protected:
    double da = 0, hra = 0, pf = 0, scf = 0;

public:
    void calc_gross_sal()
    {
        da = 0.97 * basic_sal;
        hra = basic_sal;
        pf = basic_sal;
        scf = basic_sal;
        gross_sal = da + hra + pf + scf + basic_sal;
    }

    void calc_net_sal()
    {
        // Reducing Income Taxes
        net_sal = gross_sal - (0.15) * gross_sal;
    }

    void accept()
    {
        Employee::accept();
        cout << "Enter the basic Salary of the Team Leader : " << endl;
        cin >> basic_sal;
        calc_gross_sal();
        calc_net_sal();
    }

    void display()
    {
        Employee::display();
        cout << "The Gross Salary is: " << gross_sal << endl;
        cout << "The Net Salary is: " << net_sal << endl;
    }
};

class AssistantProjectManager : public Employee
{

protected:
    double da = 0, hra = 0, pf = 0, scf = 0;

public:
    void calc_gross_sal()
    {
        da = 0.97 * basic_sal;
        hra = basic_sal;
        pf = basic_sal;
        scf = basic_sal;
        gross_sal = da + hra + pf + scf + basic_sal;
    }

    void calc_net_sal()
    {
        // Reducing Income Taxes
        net_sal = gross_sal - (0.15) * gross_sal;
    }

    void accept()
    {
        Employee::accept();
        cout << "Enter the basic Salary of the Assistant Project Manager :" << endl;
        cin >> basic_sal;
        calc_gross_sal();
        calc_net_sal();
    }

    void display()
    {
        Employee::display();
        cout << "The Gross Salary is: " << gross_sal << endl;
        cout << "The Net Salary is: " << net_sal << endl;
    }
};

class ProjectManager : public Employee
{

protected:
    double da = 0, hra = 0, pf = 0, scf = 0;

public:
    void calc_gross_sal()
    {
        da = 0.97 * basic_sal;
        hra = basic_sal;
        pf = basic_sal;
        scf = basic_sal;
        gross_sal = da + hra + pf + scf + basic_sal;
    }

    void calc_net_sal()
    {
        // Reducing Income Taxes
        net_sal = gross_sal - (0.15) * gross_sal;
    }

    void accept()
    {
        Employee::accept();
        cout << "Enter the basic Salary of the Project Manager :" << endl;
        cin >> basic_sal;
        calc_gross_sal();
        calc_net_sal();
    }

    void display()
    {
        Employee::display();
        cout << "The Gross Salary is: " << gross_sal << endl;
        cout << "The Net Salary is: " << net_sal << endl;
    }
};

int main()
{
    cout << "Welcome to Employee Payroll Management System" << endl
         << endl;

    int choice = 1, number = 1;

    do
    {
        cout << "\n\nWhose Details do you wanna enter? " << endl;
        cout << "1. Programmer\n2. Team Leader\n3. Assistant Project Manager\n4. Project Manager\n5. Quit\n";
        cin >> choice;

        if (choice == 1)
        {
            cout << "How many Programmers are we talking? ";
            cin >> number;
            Programmer pr[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Programmer" << endl;
                pr[i].accept();
            }
            cout << "\nHere is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;

            cout << "Programmer" << endl;

            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Programmer " << i + 1 << endl;
                pr[i].display();
                cout << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "How many Team Leaders are we talking? ";
            cin >> number;
            TeamLeader tl[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Team Leader " << i + 1 << endl;
                tl[i].accept();
            }
            cout << "Here is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;
            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Team Leader " << i + 1 << endl;
                tl[i].display();
                cout << endl;
            }
            cout << endl
                 << endl;
        }
        else if (choice == 3)
        {
            cout << "How many Assistant Project Managers are we talking? ";
            cin >> number;
            AssistantProjectManager ap[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Assitant Project Manager " << i + 1 << endl;
                ap[i].accept();
            }
            cout << "Here is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;
            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Assitant Project Manager " << i + 1 << endl;
                ap[i].display();
                cout << endl;
            }
            cout << endl
                 << endl;
        }

        else if (choice == 4)
        {
            cout << "How many Project Managers are we talking? ";
            cin >> number;
            ProjectManager pm[number];
            for (int i = 0; i < number; i++)
            {
                cout << "Enter the Information about the Project Manager " << i + 1 << endl;
                pm[i].accept();
            }
            cout << "Here is their Information and their Pay Slips" << endl;
            cout << endl
                 << endl;
            for (int i = 0; i < number; i++)
            {
                cout << "Info and Pay Slip of Project Manager " << i + 1 << endl;
                pm[i].display();
                cout << endl;
            }
        }
    } while (choice != 5);

    return 0;
}