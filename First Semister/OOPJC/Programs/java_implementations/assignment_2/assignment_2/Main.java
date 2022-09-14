import java.util.Scanner;

class Employee {
    Scanner input = new Scanner(System.in);
    String name;
    int emp_id;
    double salary;
    int hike = 0;

    final static int full_time_hike_perc = 100;
    final static int intern_hike_perc = 50;

    void accept() {
        System.out.println("Enter the Employee Name");
        name = input.next();
        System.out.println("Enter The Employee ID");
        emp_id = input.nextInt();
        System.out.println("Enter The Employee Salary");
        salary = input.nextInt();
    }

    void display_salary() {
        System.out.println("The Employee Name is: " + name);
        System.out.println("The Employee ID is: " + emp_id);
    }
}

class FullTimeEmployee extends Employee {
    double hiked_salary = 0;

    void calculate_salary() {
        hiked_salary = salary + salary * (full_time_hike_perc / 100);
    }

    @Override
    void display_salary() {
        super.display_salary();
        System.out.println("The Salary Before the Hike for this Full time Employee is: " + salary);
        calculate_salary();
        System.out.println("The Salary after the Hike for this Full time Employee is : " + hiked_salary);
    }
}

class InternEmployee extends Employee {
    double hiked_salary = 0;

    void calculate_salary() {
        hiked_salary = Employee::salary + salary * (full_time_hike_perc / 100);
    }

    @Override
    void display_salary() {
        super.display_salary();
        System.out.println("The Salary Before the Hike for this Intern Employee is: " + salary);
        calculate_salary();
        System.out.println("The Salary after the Hike for this Intern Employee is : " + hiked_salary);
    }
}

class Main {
    public static void main(String args[]) {
        System.out.println("Welcome to Salary Hiking Program");
        Employee emp = new Employee();
        emp.accept();
        FullTimeEmployee full_time_emp = new FullTimeEmployee();
        full_time_emp.display_salary();
        InternEmployee intern_emp = new InternEmployee();
        intern_emp.display_salary();
    }
}