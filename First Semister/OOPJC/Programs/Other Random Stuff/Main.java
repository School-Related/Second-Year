import java.util.*;

class Student {
	Scanner in = new Scanner(System.in);

	int count = 0;
	String name;
	int id;
	double grade;

	Student() {
		name = "William";
		id = 2012066034;
		grade = 65.7;
	}

	void SetName() {
		System.out.println("Enter name of Student :");
		name = in.nextLine();
		for (int i = 0; i <= name.length(); i++) {
			count++;
		}
		if (count > 20)
			System.out.println("Name Exceeded 20 characters.");
		else
			SetId();
	}

	void SetId() {
		System.out.println("Enter Id of Student :");
		id = in.nextInt();
		SetGrade();

	}

	void SetGrade() {
		System.out.println("Enter Grade of Student :");
		grade = in.nextDouble();
		if (grade <= 60)
			System.out.println("Grade is less than 60.");
		if (grade >= 100)
			System.out.println("Grade is Greater than 100.");
		else
			Display();
	}

	void Display() {
		System.out.println("Name of the Student :" + name);
		System.out.println("Id of the Student :" + id);
		System.out.println("Grade of the Student :" + grade);
	}

}

class Main {
	static Scanner in = new Scanner(System.in);
	public static void main(String args[]) {

		System.out.println("Enter how many students name you want to enter. (less than 25) ");
		int n = in.nextInt();
		Student s[] = new Student[n];
		for (int i = 0; i < n; i++) {
			s[i] = new Student();
			s[i].SetName();
		}
	}
}