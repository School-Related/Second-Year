import java.util.Scanner;

public class Assignment_1 {
    public static void main(String[] args) {
        System.out.println("This is the first Assignment");
        int count = 0; 

        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter the number of employees :");
        count = input.nextInt();
        Employee objs[] = new Employee[count];

        for(int i = 0;i < count;i++)
        {
            objs[i] = new Employee();
            objs[i].accept();
            objs[i].display();
        }
    }
}
