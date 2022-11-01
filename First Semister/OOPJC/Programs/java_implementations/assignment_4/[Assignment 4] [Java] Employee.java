package assignment_4;

import java.util.Scanner;

// Validate the employee record with custom exception
// Create a class employee with attributes eid, name, age and department.
// Initialize values through parameterized constructor. If age of employee is not in between
// 25 and 60 then generate user-defined exception "AgeNotWithinRangeException". If
// name contains numbers or special symbols raise exception "NameNotValidException".
// Define the two exception classes.

class AgeNotWithinRangeException extends Exception {
    public AgeNotWithinRangeException(int s) {
        // super(s);
        System.out.println("Age not within range");
    }

    @Override
    public String getMessage() {
        return "Incorrect Age!";
    }
}

class NameNotValidException extends Exception {
    public NameNotValidException(String s) {
        // super(s);
    }
}

public class Employee {
    Scanner input = new Scanner(System.in);
    int e_id, age;
    String name, department;

    int accept() {
        String specialCharactersString = "1234567890!@#$%&*()'+,-./:;<=>?[]^_`{|}";
        try {
            System.out.println("Enter the Employee ID: ");
            e_id = input.nextInt();
            System.out.println("Enter the Employee Name");
            name = input.next();

            for (int i = 0; i < name.length(); i++) {
                char ch = name.charAt(i);
                if (specialCharactersString.contains(Character.toString(ch))) {
                    System.out.println(name + " contains special character");
                    throw new NameNotValidException(name);
                }
            }
            System.out.println("Enter the Employee Age: ");
            age = input.nextInt();
            if (age > 60 || age < 25) {
                throw new AgeNotWithinRangeException(age);
            }
            System.out.println("Enter the Employee Department: ");
            department = input.next();

        } catch (AgeNotWithinRangeException e) {
            System.out.println("Age is not within the correct range.");
            return -1;
        } catch (NameNotValidException e) {
            System.out.println("Name not Valid");
            return -1;
        }
        return 0;
    }

    void display() {
        System.out.println("Employee ID is : " + e_id);
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Age: " + age);
        System.out.println("Employee Department: " + department);
    }

}
