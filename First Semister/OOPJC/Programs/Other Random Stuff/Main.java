import java.util.Scanner;

class Commission {
	public int sales = 0;

	Commission(int sales) {
		this.sales = sales;
	}

	// returns the commission
	public double commission() {
		// commission can be a decimal point number. So, we use double
		double commission = 0.0;
		if (sales >= 0 && sales <= 5000) {
			commission = 0.02 * (double) sales;
		} else if (sales > 5000 && sales <= 10000) {
			commission = 0.05 * (double) sales;
		} else if (sales > 10000) {
			commission = 0.08 * (double) sales;
		}
		return commission;
	}

}

// Now write a demo class to test the
// Commission class by reading a sale from the user, using it to create a
// Commission object after validating that the value is not negative. Finally,
// call the commission()
// method to get and print the
// commission. If the sales are negative, your demo should print the message
// “Invalid Input”.
class Demo {
	static Scanner scan = new Scanner(System.in);

	public static void runDemo() {
		System.out.println("Enter sales");
		try {
			int sales = scan.nextInt();
			if (sales >= 0) {
				Commission commission = new Commission(sales);
				System.out.println("Commission is " + commission.commission());
			} else {
				throw new Exception();
			}
		} catch (Exception e) {
			System.out.println("Invalid Input");
		}
	}
}

class Main {

	public static void main(String args[]) {
		Demo.runDemo();
	}
}