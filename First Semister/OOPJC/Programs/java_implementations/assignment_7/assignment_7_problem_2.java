// Krishnaraj Thadesar
// Batch A1, PA20
// OOPCJ Assignment 7.2
// Print even and odd numbers in increasing order using two threads in Java

import java.security.ProtectionDomain;
import java.util.Scanner;

import javax.swing.InputMap;

class printEven extends Thread implements Runnable {
    int limit;

    printEven(int limit) {
        this.limit = limit;
    }

    @Override
    public synchronized void start() {
        super.start();
        System.out.println("Printing Even Numbers");
    }

    @Override
    public void run() {
        for (int i = 0; i < limit; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
    }
}

class printOdd extends Thread implements Runnable {
    int limit;

    printOdd(int limit) {
        this.limit = limit;
    }

    @Override
    public synchronized void start() {
        super.start();
        System.out.println("Printing Odd Numbers");
    }

    @Override
    public void run() {
        for (int i = 0; i < limit; i++) {
            if (i % 2 != 0) {
                System.out.println(i);
            }
        }
    }
}

public class assignment_7_problem_2 {
    static printEven pe;
    static printOdd po;
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int limit = 0;
        System.out.println("Enter To what limit Even or Odd numbers you want to See");
        limit = input.nextInt();
        pe = new printEven(limit);
        po = new printOdd(limit);
        try {
            pe.start();
            pe.join();
            po.start();
            po.join();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
