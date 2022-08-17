#include <iostream>
using namespace std;
class Employee
{
private:
    static int ssn;

public:
    int emp_id = 1000;
    int age = 0, basic_sal = 0, da = 0, ta = 0;
    string address_city, position, name;

    // Default Constructor
    Employee()
    {
        ssn += 1;
        cout << "The Default Constructor was called" << endl;
    }

    // Parameterized Constructor
    Employee(int e, int a, int b, int d, int t, string add, string pos, string nam)
    {
        cout << "Parameterized constructor was called";
        emp_id = e;
        age = a;
        basic_sal = b;
        da = d;
        ta = t;
        address_city = add;
        position = pos;
        name = nam;
    }

    // Copy Constructor
    Employee(Employee &E)
    {
        cout << "Copy Constructor was called" << endl;
        emp_id = E.emp_id;
        age = E.age;
        basic_sal = E.basic_sal;
        da = E.da;
        ta = E.ta;
        address_city = E.address_city;
        position = E.position;
        name = E.name;
    }

    void display()
    {
        cout << "Employee ssn is:" << ssn << endl;
        cout << "Employee ID is : " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Age: " << age << endl;
        cout << "Employee Position: " << position << endl;
        cout << "Employee basic Salary: " << basic_sal << endl;
        cout << "Employee DA: " << da << endl;
        cout << "Employee TA: " << ta << endl;
        cout << "Employee Gross Salary: " << calc_gross_sal() << endl;
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
        cout << "Enter the Employee Position: " << endl;
        cin >> position;
        cout << "Enter the Employee basic Salary: " << endl;
        cin >> basic_sal;
        cout << "Enter the Employee DA: " << endl;
        cin >> da;
        cout << "Enter the Employee TA: " << endl;
        cin >> ta;
        cout << "Enter the Employee Address City: " << endl;
        cin >> address_city;
    }

    float calc_gross_sal()
    {
        int gross_sal = da + ta + basic_sal - (.15 * basic_sal);
        return gross_sal;
    }

    // Destructor
    ~Employee()
    {
        cout << "The Destructor was called" << endl;
    }
};

int Employee::ssn = 1000;

int main()
{
    // Defining an Object using the default Constructor
    Employee CEO;
    CEO.emp_id = 1000;
    CEO.name = "Kom Pany Seeio";
    CEO.address_city = "Seoul";
    CEO.age = 45;
    CEO.basic_sal = 1000000;
    CEO.da = 1000;
    CEO.ta = 2000;
    CEO.position = "CEO";

    // Defining an object using the copy constructor
    Employee President(CEO);
    President.name = "Precy Dent";
    President.age = 45;
    President.address_city = "Delhi";
    President.basic_sal *= 2;
    President.position = "President";

    // Taking user input for the number of employees
    int count = 0;
    cout << "How many values do you wanna input ?";
    cin >> count;

    // Dynamically Creating new Objects
    Employee *Obj = new Employee[count];
    cout << "Enter the Details" << endl;

    // Accepting Objects from the User.
    for (int i = 0; i < count; i++)
    {
        cout << "Enter information about the Employee Number: " << i << endl;
        Obj[i].accept();
    }

    // Displaying Information about the CEO and the President
    cout << "Information about the CEO" << endl;
    CEO.display();
    cout << "Information about the President" << endl;
    President.display();

    // Displaying Information about the other Employees
    for (int i = 0; i < count; i++)
    {
        cout << "Information about the Employee Number: " << i << endl;
        Obj[i].display();
    }

    delete[] Obj;
    return 0;
}

