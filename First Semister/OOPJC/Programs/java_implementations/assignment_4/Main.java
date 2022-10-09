// P1
// Implement the program to handle the arithmetic exception, ArrayIndexOutofBounds .
// The user enters the two numbers: n1, n2. The division of n1 and n2 is displayed. If n1, n2
// are not integers then program will throw number format exception. If n2 is zero the
// program will throw Arithmetic exception.

// P2
// Validate the employee record with custom exception
// Create a class employee with attributes eid, name, age and department.
// Initialize values through parameterized constructor. If age of employee is not in between
// 25 and 60 then generate user-defined exception "AgeNotWithinRangeException". If
// name contains numbers or special symbols raise exception "NameNotValidException".
// Define the two exception classes.

// P3
// Write a menu-driven program for banking system which accept the personal data for
// Customer(cid, cname, amount).
// Implement the user-defined/standard exceptions, wherever required to handle the
// following situations:
// Account should be created with minimum amount of 1000 rs..
// For withdrawal of amount, if wth_amt greater than amount.
// cid should be in the specific range of 1 to 20.
// Entered amount should be positive.

package assignment_4;

public class Main {

    public static void program_3() {
        Bank obj = new Bank();
        if (obj.accept() == 1) {
            System.out.println("Data entered Correctly!");
            obj.display();
        } else {
            System.out.println("Data entered Incorrectly!");
        }
    }

    public static void program_2() {
        Division d = new Division();
        d.accept();
        System.out.println("Dividing the inputs: ");
        System.out.println(d.divide());

    }

    public static void program_1() {

        Employee obj = new Employee();
        if (obj.accept() >= 0) {
            obj.display();
        }
    }

    public static void main(String args[]) {

        // program_1();
        program_2();
        program_3();

    }
}
