package assignment_2;
import java.util.Scanner;

class Employee
{
    Scanner input = new Scanner(System.in);
    String name;
    int emp_id;
    double salary;
    int hike = 0;

    final static int full_time_hike_perc = 100;
    final static int intern_hike_perc = 50;

    void accept()
    {
        System.out.println("Enter the Employee Name");
        name = input.next();
        System.out.println("Enter The Employee ID");
        emp_id = input.nextInt(); 
        System.out.println("Enter The Employee Salary");
        salary = input.nextInt();   
    }

    void display_salary()
    {
        System.out.println("The Employee Name is: " + name);
        System.out.println("The Employee ID is: " + emp_id);
    }
}

