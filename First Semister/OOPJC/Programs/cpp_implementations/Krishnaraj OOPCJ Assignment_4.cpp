
// Define a class Employee consisting following:
// Data members: a. Employee ID, b. Name of Employee, c. Age, d. Income, e. City, f. Vehicle
// Member Functions: a. To assign initial values, b. To display.

// Accept Employee ID, Name, Age, Income, City and Vehicle from the user. Create
// an exception to check the following conditions and throw an exception if the
// condition does not meet.

// Employee age between 18 and 55
// Employee income between Rs. 50,000 to Rs. 1,00,000 per month
// Employee staying in Pune/ Mumbai/ Bangalore / Chennai
// Employee having 4-wheeler

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
public:
    int emp_id, age, income;
    string name, city;
    bool has_vehicle, data_entered_correctly;

    Employee()
    {
        emp_id = 1;
        age = 30;
        income = 10000;
        name = "William";
        city = "Pune";
        has_vehicle = true;
        cout << "The default values are: " << endl;
        data_entered_correctly = true;
        display();
    }

    int accept()
    {

        cout << "Enter the information of the new Employee : " << endl;
        cout << "Enter the Employee ID: " << endl;
        cin >> emp_id;
        cout << "Enter the Employee Name: " << endl;
        cin >> name;
    age:
        cout << "Enter the Employee Age: " << endl;
        try
        {
            cin >> age;
            if (age <= 18 || age >= 55)
            {
                throw age;
            }
        }
        catch (int e)
        {
            cout << "Exception Caught!, Age is not in the valid limit. " << endl;
            data_entered_correctly = false;
            goto age;
        }
    salary:
        cout << "Enter the Employee basic Salary: " << endl;
        try
        {
            cin >> income;
            if (income <= 50000 || income >= 100000)
            {
                throw 'a';
            }
        }
        catch (char e)
        {
            cout << "Exception Caught!, Income is not in the valid limit. " << endl;
            data_entered_correctly = false;
            goto salary;
        }
    city:
        cout << "Enter the Employee Address City: " << endl;
        try
        {
            cin >> city;
            if (city != "Mumbai" && city != "Pune" && city != "Bangalore")
            {
                throw 1.1;
            }
        }
        catch (double e)
        {
            cout << "Exception Caught!, City Entered Incorrectly " << endl;
            data_entered_correctly = false;
            goto city;
        }
    vehicle:
        cout << "Does the Employee have a vehicle? (Y, N) " << endl;
        try
        {
            char inp;
            cin >> inp;
            if (inp != 'Y')
            {
                throw has_vehicle;
            }
        }
        catch (bool e)
        {
            cout << "Exception Caught!, You must have a vehicle!" << endl;
            data_entered_correctly = false;
            goto vehicle;
        }
        data_entered_correctly = true;
        return 0;
    }

    void display()
    {
        if (data_entered_correctly)
        {
            cout << "Employee ID is : " << emp_id << endl;
            cout << "Employee Name: " << name << endl;
            cout << "Employee Age: " << age << endl;
            cout << "Employee Income : " << income << endl;
            cout << "Employee Address City: " << city << endl;
            cout << "Does Employee have a vehicle? : " << has_vehicle << endl;
        }
        else
        {
            cout << "You didnt enter the Data Correctly" << endl;
        }
    }
};

int main()
{
    cout << "Welcome to Assignment 4: Error Safe Employee Data Input Program" << endl;
    Employee obj;
    obj.accept();
    obj.display();
    if (!obj.data_entered_correctly)
    {
        cout << "Please Try again";
    }
    else
    {
        cout << "You have entered the data correctly! " << endl;
    }
    return 0;
}