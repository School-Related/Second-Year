import java.util.Scanner;
import java.util.InputMismatchException;

// create student class.
class StudentManagement extends Exception {
	StudentManagement(String error) {
		super(error);
	}
}

public class Main {
	static double m1, m2, m3, m4, m5, m6;
	static String name;
	static Scanner in = new Scanner(System.in);
	static double percentage;

	public static void main(String arg[]) {

		try {
			System.out.println("Enter The name of the Student: ");
			name = in.next();
			// create object of scanner class.

			// enter marks between 1-50
			System.out.print("Enter marks for subject 1 here\n : ");
			double m1 = in.nextInt();

			System.out.print("Enter marks for subject 2 here\n : ");
			double m2 = in.nextInt();

			System.out.print("Enter marks for subject 3 here \n: ");
			double m3 = in.nextInt();

			System.out.print("Enter marks for subject 4 here \n: ");
			double m4 = in.nextInt();

			System.out.print("Enter marks for subject 5 here \n: ");
			double m5 = in.nextInt();

			System.out.print("Enter marks for subject 6 here \n: ");
			double m6 = in.nextInt();

			// condition for checking valid entry of marks.
			if (!(m1 >= 0 && m1 <= 50) || !(m2 >= 0 && m2 <= 50) || !(m3 >= 0 && m3 <= 50) || !(m4 >= 0 && m4 <= 50)
					|| !(m5 >= 0 && m5 <= 50) || !(m6 >= 0 && m6 <= 50)) {
				throw (new StudentManagement("Invalid marks:"));
			}

			System.out.println("The Name of the student is: " + name);
			System.out.println("Entered marks for subject 1 are :" + m1);
			System.out.println("Entered marks for subject 1 are :" + m2);
			System.out.println("Entered marks for subject 1 are :" + m3);
			System.out.println("Entered marks for subject 1 are :" + m4);
			System.out.println("Entered marks for subject 1 are :" + m5);
			System.out.println("Entered marks for subject 1 are :" + m6);

			percentage =  ((m1 + m2 + m3 + m4 + m5 + m6) * 0.01)/6;
			System.out.println("The Percentage is: " + percentage);

		} catch (InputMismatchException e) {
			System.out.println("Invalid Input..Pls Input Integer Only..");
		} catch (StudentManagement e) {
			System.out.println("Error:" + e);
		}

	}
}