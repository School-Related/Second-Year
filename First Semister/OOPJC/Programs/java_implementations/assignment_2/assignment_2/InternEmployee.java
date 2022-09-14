package assignment_2;

class InternEmployee extends Employee {
    double hiked_salary = 0;

    void calculate_salary() {
        hiked_salary = salary + salary * (full_time_hike_perc / 100);
    }

    @Override
    void display_salary() {
        super.display_salary();
        System.out.println("The Salary Before the Hike for this Intern Employee is: " + salary);
        calculate_salary();
        System.out.println("The Salary after the Hike for this Intern Employee is : " + hiked_salary);
    }
}