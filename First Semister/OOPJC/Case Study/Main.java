// C++ and Java Program to Calculate Average of elements in an Integer Arrays.Take input values.Also display number of elements which are greater than average value.
// Krishnaraj Thadesar 
// PA 20 Batch A1

import java.util.*;;

public class Main {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        int size = 10;
        int greater = 0;
        double average = 0;
        System.out.println("Enter the size of the Array that you want to enter");
        size = input.nextInt();
        Double arr[] = new Double[size];
        System.out.println("Enter the Elements of the Array: ");
        for (int i = 0; i < size; i++) {
            arr[i] = input.nextDouble();
            average += arr[i];
        }
        average /= size;
        System.out.println("The Average of All the Elements that you have entered is: " + average);
        System.out.println("The Elements that are above the Average of all the elements are: ");
        for (int i = 0; i < size; i++) {
            if (arr[i] > average) {
                System.out.println(arr[i] + " ");
                greater++;
            }
        }
        System.out.println("The Number of elements greater than the Average is: " + greater);
    }
}