mport java.util.*;

public class Main {
  static Scanner sc = new Scanner(System.in);

  // assuming that the digits of the factorial of a number can not exceed 19
  // Digits.
  long result[] = new long[19];

  // Method for Finding Factorial
  public int factorial(int x) // Here X is the number we want to find the factorial of
  {
    // Initialize the result array
    result[0] = 1;
    int resultSize = 1;

    // Applying the simple formula of factorial
    // f! = 1 x 2 x 3 x 4 ... x f
    for (int f = 2; f <= x; f++) {
      resultSize = multiply(f, result, resultSize);
    }

    return resultSize;
  }

  // The following method multiplies x with the number
  // represented by the result[] array. resultSize is the size of the result[]
  // array
  // or the number of digits present in the number that is represented by
  // result[].
  // The method uses the basic school mathematics for
  // the multiplication. The method may increase the value of resultSize
  // and returns a new value of the resultSize
  static int multiply(int y, long result[], int resultSize) {
    int c = 0; // Initializing the carry
    // performing the basic multiplication
    // and updating the result array
    for (int j = 0; j < resultSize; j++) {
      int product = (int) result[j] * y + c;
      result[j] = product % 10; // Storing the last digit of
      // 'product' in the result[] array
      c = product / 10; // Put the rest in c
    }
    // Putting the carry in the result[] array and increase the result size
    // resultSize
    while (c != 0) {
      result[resultSize] = c % 10;
      c = c / 10;
      resultSize = resultSize + 1;
    }
    return resultSize;
  }

  // main method
  public static void main(String argvs[]) {

    System.out.print("**Enter the Number of which you want to Find factorial*: ");
    int x = sc.nextInt();
    try {
      if (x <= 0) {
        throw new IllegalArgumentException("Value of x must be positiveb!.");
      }
      if (x >= 20)
        throw new IllegalArgumentException("Result will Overflow");
    } catch (IllegalArgumentException a) {
      System.out.println(a);

      System.exit(0);
    }

    // creating an object of the class LargeNumFact
    Main obj = new Main();
    // storing the result of the method factorial()
    int resSize = obj.factorial(x);
    System.out.println("The factorial of the number " + x + " is: ");
    // printing the result
    for (int j = resSize - 1; j >= 0; j--) {
      System.out.print(obj.result[j]);

    }

  }
}