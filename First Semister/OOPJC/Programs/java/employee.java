import java.util.Scanner;
    // create an object of Scanner
    
    
class Employee {
    Scanner input = new Scanner(System.in);
    int emp_id;
    int age, basic_sal, da, ta;
    String address_city, position, name;


    void Employee()
    {
        System.out.println("Default Constructor was called");
    }

    // Parameterized Constructor
    void Employee(int e, int a, int b, int d, int t, String add, String pos, String nam)
    {
        System.out.println("Parameterized constructor was called");
        emp_id = e;
        age = a;
        basic_sal = b;
        da = d;
        ta = t;
        address_city = add;
        position = pos;
        name = nam;
    }

    double calc_gross_sal()
    {
        return basic_sal + da + ta - (0.15 * basic_sal);
    }

    void display()
    {
        // System.out.println("Employee ssn is: " + );
        System.out.println("Employee ID is : " + emp_id);
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Age: " + age);
        System.out.println("Employee Position: " + position);
        System.out.println("Employee basic Salary: " + basic_sal);
        System.out.println("Employee DA: " + da);
        System.out.println("Employee TA: " + ta);
        System.out.println("Employee Gross Salary: " + calc_gross_sal() );
        System.out.println("Employee Address City: " + address_city);
    }

        

    void accept()
    {
        
        System.out.println("Enter the age :");
        age = input.nextInt();
        System.out.println("Employee ID is: ");
        emp_id = input.nextInt();
        System.out.println("Employee Name: " );
        name = input.next();
        System.out.println("Employee Age: " );
        age = input.nextInt();
        System.out.println("Employee Position: " );
        position = input.next();
        System.out.println("Employee basic Salary: ");
        basic_sal = input.nextInt();
        System.out.println("Employee DA: ");
        da = input.nextInt();
        System.out.println("Employee TA: ");
        ta = input.nextInt();
        System.out.println("Employee Address City: ");
        address_city = input.next();
    }
}