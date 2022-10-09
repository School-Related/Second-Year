// Write a java program to create two interfaces Motorbike and Cycle.
// Motorbike interface consists of the attribute speed.
// The method is totalDistance().
// Cycle interface consists of the attributes distance and the method speed().
// These interfaces are implemented by the class TwoWheeler.
// Calculate total distance travelled and Average Speed maintained by Two Wheeler.

package assignment_2b;

import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        TwoWheeler obj = new TwoWheeler();

        System.out.println("Calculating Speed: ");
        System.out.println("Enter the Distance Travelled by Your 2 Wheeler: ");
        obj.total_distance = input.nextInt();

        System.out.println("Enter the Time you Travelled on Your 2 Wheeler: ");
        obj.time = input.nextInt();

        System.out.println("The Speed is: ");
        obj.speed();

        System.out.println("Calculating Total Distance: ");
        System.out.println("Enter the Speed of Your 2 Wheeler: ");
        obj.speed = input.nextInt();

        System.out.println("Enter the Time you Travelled on Your 2 Wheeler: ");
        obj.time = input.nextInt();

        System.out.println("The Total Distance is: ");
        obj.totalDistance();
    }
}