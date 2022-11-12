import java.lang.Thread;
import java.util.Scanner;

class Calculator extends Thread implements Runnable {
    public int a, b, what_to_do = 0;

    Calculator(int a, int b, int choice, String name) {
        this.a = a;
        this.b = b;
        this.what_to_do = choice;
        this.setName(name);
    }

    @Override
    public synchronized void start() {
        System.out.println("Starting the Thread");
        System.out.println("The Name of this Thread is: " + getName());
        super.start();
    }

    @Override
    public void run() {
        switch (what_to_do) {
            case 1:
                System.out.println(a + b);
                break;
            case 2:
                System.out.println(a - b);
                break;
            case 3:
                System.out.println(a * b);
                break;
            case 4:
                try {
                    System.out.println(a / b);
                } catch (ArithmeticException e) {
                    System.out.println("You cant Divide by Zero!");
                }
                break;
            default:
                break;
        }
    }
}

public class assignment_7_problem_1 {
    public static Calculator add, sub, mul, div;
    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int choice = 0;
        int a, b;
        System.out.println("Welcome To Thread Calculator of Assignment 7");
        while (choice != 5) {
            System.out.println("What would you like to do? ");
            System.out.println(
                    "1. Addition of 2 Numbers\n2. Subtraction of 2 Numbers\n3. Multiplication of 2 Numbers\n4. Division of 2 Numbers\n\n");
            choice = input.nextInt();
            if (choice == 5) {
                break;   
            }
            System.out.println("Enter the 2 Numbers");
            a = input.nextInt();
            b = input.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("You have chosen Addition!");
                    add = new Calculator(a, b, choice, "Adder");
                    try {
                        add.start();
                        add.join();
                    } catch (Exception e) {
                        System.out.println("Got some problem with making the thread!");
                        System.out.println(e);
                    }
                    break;
                case 2:
                    System.out.println("You have chosen Subtraction!");
                    sub = new Calculator(a, b, choice, "Subtractor");
                    try {
                        sub.start();
                        sub.join();
                    } catch (Exception e) {
                        System.out.println("Got some problem with making the thread!");
                        System.out.println(e);
                    }
                    break;
                case 3:
                    System.out.println("You have chosen Multiplication!");
                    mul = new Calculator(a, b, choice, "Multiplier");
                    try {
                        mul.start();
                        mul.join();
                    } catch (Exception e) {
                        System.out.println("Got some problem with making the thread!");
                        System.out.println(e);
                    }
                    break;
                case 4:
                    System.out.println("You have chosen Division!");
                    div = new Calculator(a, b, choice, "Divider");
                    try {
                        div.start();
                        div.join();
                    } catch (Exception e) {
                        System.out.println("Got some problem with making the thread!");
                        System.out.println(e);
                    }
                    break;
                case 5:
                    System.out.println("You have chosed to Exit!");
                default:
                    break;
            }

        }
        System.exit(0);
    }
}
