
// Write a Java Program for demonstrating Inheritance in Java.
// Write a program in Java showing hierarchical inheritance with base class as Employee and
// derived classes as FullTimeEmployee and InternEmployee with methods DisplaySalary in
// base class and CalculateSalary in derived classes.
// Calculate salary method will calculate as per increment given to fulltime and intern
// Employees. Fulltime employee- 50% hike, Intern employee-25% hike. Display salary
// before and after hike.


package assignment_2;

import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        System.out.println("Welcome to Salary Hiking Program");
        Employee emp = new Employee();
        FullTimeEmployee full_time_emp = new FullTimeEmployee();
        System.out.println("Enter the Details about the Full Time Employee: \n");
        full_time_emp.accept();
        full_time_emp.display_salary();
        InternEmployee intern_emp = new InternEmployee();
        System.out.println("Enter the Details about the Intern Employee: \n");
        intern_emp.accept();
        intern_emp.display_salary();
    }
}