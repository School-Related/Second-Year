import java.util.Scanner;

public class Main {

  public static void main(String args[]) {
    int row1, col1, row2, col2;
    Scanner s = new Scanner(System.in);

    // Input dimensions of First Matrix: A
    System.out.print("Enter number of rows in first matrix: ");
    row1 = s.nextInt();

    System.out.print("Enter number of columns in first matrix: ");
    col1 = s.nextInt();

    // Input dimensions of second matrix: B
    System.out.print("Enter number of rows in second matrix: ");
    row2 = s.nextInt();

    System.out.print("Enter number of columns in second matrix: ");
    col2 = s.nextInt();

    // Requirement check for matrix multiplication
    try {
      if (col1 != row2) {
        throw new Exception();
      }
    } catch (Exception e) {
      System.out.println("The no of columns in first matrix has to be same as the no of rows in second matrix");
      System.exit(0);
    }

    int a[][] = new int[row1][col1];
    int b[][] = new int[row2][col2];
    int c[][] = new int[row1][col2];

    // Input the values of matrices
    System.out.println("\nEnter values for matrix A : ");
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col1; j++)
        a[i][j] = s.nextInt();
    }
    System.out.println("\nEnter values for matrix B : ");
    for (int i = 0; i < row2; i++) {
      for (int j = 0; j < col2; j++)
        b[i][j] = s.nextInt();
    }

    // Perform matrix multiplication
    // Using for loop
    System.out.println("\nMatrix multiplication is : ");
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col2; j++) {
        // Initialize the element C(i,j) with zero
        c[i][j] = 0;

        // Dot product calculation
        for (int k = 0; k < col1; k++) {
          c[i][j] += a[i][k] * b[k][j];
        }

        System.out.print(c[i][j] + " ");
      }
      System.out.println();
    }
  }
}