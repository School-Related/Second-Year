// Develop an object-oriented program to create a database of employee information system
// containing the following information: Employee Name, Employee number, qualification,
// address, contact number, salary details (basic, DA, TA, Net salary), etc. Construct the
// database with suitable member functions for initializing and destroying the data viz.
// constructor, default constructor, Copy constructor, destructor. Use dynamic memory
// allocation concept while creating and destroying the object of a class. Use static data
// member concept wherever required. Accept and display the information of Employees.

package assignment_1;

import java.util.Scanner;

public class Source {

    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("This is the first Assignment");
        int count = 0;

        // Default Constructor
        Employee CEO = new Employee();
        CEO.emp_id = 1000;
        CEO.name = "Kom Pany Seeio";
        CEO.address_city = "Seoul";
        CEO.age = 45;
        CEO.basic_sal = 1000000;
        CEO.da = 1000;
        CEO.ta = 2000;
        CEO.position = "CEO";

        // Defining an object using the copy constructor
        Employee President = new Employee(CEO);
        President.name = "Precy Dent";
        President.age = 45;
        President.address_city = "Delhi";
        President.basic_sal *= 2;
        President.position = "President";

        Employee VP = new Employee(1003, 50, 200000, 3000, 1000,
                "Mumbai", "Vice President", "Visey Presed Ent");

        System.out.println("Information about the CEO");
        CEO.display();
        System.out.println("Information about the President");
        President.display();
        System.out.println("Information about the President");
        VP.display();

        System.out.println("Enter the number of employees :");
        count = input.nextInt();
        Employee objs[] = new Employee[count];

        for (int i = 0; i < count; i++) {
            objs[i] = new Employee();
            objs[i].accept();
            objs[i].display();
        }
        System.gc();
    }
}
