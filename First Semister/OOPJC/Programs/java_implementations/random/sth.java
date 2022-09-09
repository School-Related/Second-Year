import java.util.Scanner;

class Employee {

    // create an object of Scanner
    Scanner input = new Scanner(System.in);
    
    int emp_id;
    int age, basic_sal, da, ta;
    String address_city, position, name;
    static int ssn;

    Employee()
    {
        System.out.println("Default Constructor was called");
    }

    // Parameterized Constructor
    Employee(int e, int a, int b, int d, int t, String add, String pos, String nam)
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
    
    // Copy Constructor
    Employee(Employee E)
    {
        System.out.println("Copy constructor was called");
        emp_id = E.emp_id;
        age = E.age;
        basic_sal = E.basic_sal;
        da = E.da;
        ta = E.ta;
        address_city = E.address_city;
        position = E.position;
        name = E.name;
    }

    double calc_gross_sal()
    {
        return basic_sal + da + ta - (0.15 * basic_sal);
    }

    void display()
    {   
        ssn = ssn + 1;
        System.out.println("Employee ssn is: " + ssn);
        System.out.println("Employee ID is : " + emp_id);
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Age: " + age);
        System.out.println("Employee Position: " + position);
        System.out.println("Employee basic Salary: " + basic_sal);
        System.out.println("Employee DA: " + da);
        System.out.println("Employee TA: " + ta);
        System.out.println("Employee Gross Salary: " + calc_gross_sal() );
        System.out.println("Employee Address City: " + address_city);
        System.out.println("\n");
    }

    void accept()
    {
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
    // @Override
    // protected void finalize() throws Throwable
    // {
    //     try
    //     {
    //         input.close();
    //         System.out.println("Garbage collector called the finalize method. ");
    //     } 
    //     catch(Throwable t) 
    //     {
    //         throw t;
    //     } 
    //     finally
    //     {
    //         super.finalize();
    //     }
    // }

}


class Source {

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

        Employee VP = new Employee(1003, 50, 200000, 3000, 1000, "Mumbai", "Vice President", "Visey Presed Ent");

        
        System.out.println("Information about the CEO");
        CEO.display();
        System.out.println("Information about the President");
        President.display();
        System.out.println("Information about the President");
        VP.display();

        System.out.println("Enter the number of employees :");
        count = input.nextInt();
        Employee objs[] = new Employee[count];

        for(int i = 0;i < count;i++)
        {
            objs[i] = new Employee();
            objs[i].accept();
            objs[i].display();
        }
        System.gc();

    }
}
