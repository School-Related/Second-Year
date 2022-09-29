package assignment_4;

import java.util.*;

public class Bank {
    public int minimum_sal;
    public int withdrawal_amt;
    public int amount;
    public int c_id;
    Scanner input = new Scanner(System.in);

    public void accept() {
        System.out.println("Enter the customer id: ");
        try {
            c_id = input.next();
            if (c_id > 20 || c_id < 0) {
                throw 1;
            }
        } catch (int e) {
            System.out.println("Wrong customer id");
        }
    }

    public void display() {
        System.out.println("The Customer ID is: ");
        System.out.println(c_id);
    }
}
