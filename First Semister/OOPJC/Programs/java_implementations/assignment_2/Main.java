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