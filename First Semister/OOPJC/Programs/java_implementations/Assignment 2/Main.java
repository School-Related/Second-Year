package assignment_2;

class Main {
    public static void main(String args[])
    {
        System.out.println("Welcome to Salary Hiking Program");
        Employee emp = new Employee();
        emp.accept();
        FullTimeEmployee full_time_emp = new FullTimeEmployee();
        full_time_emp.display_salary();
        InternEmployee  intern_emp = new InternEmployee();
        intern_emp.display_salary();
    }
}