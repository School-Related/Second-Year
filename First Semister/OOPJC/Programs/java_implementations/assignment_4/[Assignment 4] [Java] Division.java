package assignment_4;

import java.util.InputMismatchException;
import java.util.Scanner;

// Implement the program to handle the arithmetic exception, ArrayIndexOutofBounds .
// The user enters the two numbers: n1, n2. The division of n1 and n2 is displayed. If n1, n2
// are not integers then program will throw number format exception. If n2 is zero the
// program will throw Arithmetic exception.

// class NumberFormatException extends Exception
// {
//     public NumberFormatException(String s)
//     {
//         super(s);
//     }

//     @Override
//     public String getMessage()
//     {
//         return "What is this";
//     }
// }  

public class Division {
    int n1;
    int n2;
    int ans;
    Scanner input = new Scanner(System.in);

    void accept() {
        System.out.println("Enter the Numbers that you want to divide. ");
        try {
            n1 = input.nextInt();
            n2 = input.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Number Format Exception, the format you entered does not match. ");
        }
    }

    int divide() {
        try {
            ans = n1 / n2;
        } catch (ArithmeticException e) {
            System.out.println("Exception Caught! Cant divide by Zero!");
        }
        return ans;
    }

}