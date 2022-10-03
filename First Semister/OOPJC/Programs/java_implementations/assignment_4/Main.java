package assignment_4;

public class Main {

    public static void program_3() {
        Bank obj = new Bank();
        obj.accept();
        obj.display();
    }
    
    public static void program_2() {
        Division d = new Division();
        d.accept();
        System.out.printn("Dividing the inputs: ");
        System.out.println(d.divide());

    }

    public static void program_1() {

        Employee obj = new Employee();
        if (obj.accept() >= 0) {
            obj.display();
        }
    }

    public static void main(String args[]) {

        program_1();
        program_2();
        program_3();

    }
}
