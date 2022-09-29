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
            c_id = input.nextInt();
            if (c_id > 20 || c_id < 0) {
                throw new Exception("wrong cust id");
            }
        } catch (Exception e) {
            System.out.println("Wrong customer id");
        }

        System.out.println("Enter the Amount in your Account: ");
        try {
            amount = input.nextInt();
            if (amount < 1000) {
                throw new Exception("Amount less than mimimum");
            }
        } catch (Exception e) {
            System.out.println("Mimimum amount cant be less than 1000. ");
        }

        System.out.println("Enter the Withdrawal Amount: ");
        try {
            withdrawal_amt = input.nextInt();
            if (withdrawal_amt > amount) {
                throw new Exception("Withdrawal amount more than amount. ");
            } else {
                amount -= withdrawal_amt;
            }
        } catch (Exception e) {
            System.out.println("Withdrawal Amount more than amount in bank. ");
        }
    }

    public void display() {
        System.out.println("\n\nThe Customer ID is: ");
        System.out.println(c_id);
        System.out.println("The Amount in the Bank Before Withdrawing was: ");
        System.out.println(amount + withdrawal_amt);
        System.out.println("The Withdrawal Amount is: ");
        System.out.println(withdrawal_amt);
        System.out.println("The Amount Remaining in Bank is: ");
        System.out.println(amount);
    }
}
