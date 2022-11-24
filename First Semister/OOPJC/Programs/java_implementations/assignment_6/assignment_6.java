// Write a Java program to
// create a new array list and print out the collection by position
// add some elements (string)
// search an element in an array list
// reverse elements in an array list
// test an array list is empty or not
// join two array lists

// Krishnaraj Thadesar
// PA20
// Batch A1
// Assignment 6 in OOPCJ

import java.util.*;

import javax.lang.model.util.ElementScanner14;

import java.lang.*;

public class assignment_6 {
    static Scanner input = new Scanner(System.in);
    static ArrayList<String> arrayList, list1, list2;
    static String list1_input, list2_input, main_list_input;

    public static void main(String[] args) {
        System.out.println("Welcome to Assignment 6! What do you want to do? ");
        int choice = 0;
        arrayList = new ArrayList<String>();
        while (choice != 7) {
            System.out.println(
                    "\n\n1. Add some elements (string)\n2. Search an element in an array list\n3. Reverse elements in an array list\n4. Test an array list is empty or not\n5. Join two array lists\n6. Display All Elements\n7. Quit\n");
            choice = input.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter the Element that you want to enter: ");
                    main_list_input = input.next();
                    arrayList.add(main_list_input);
                    break;
                case 2:
                    System.out.println("Enter the Element that you want to Search: ");
                    main_list_input = input.next();
                    // search an element in ArrayList
                    if (arrayList.contains(main_list_input)) {
                        System.out.println("Element found");
                    } else {
                        System.out.println("Element not found");
                    }
                    break;
                case 4:
                    System.out.println("Checking if Arraylist is Empty: ");
                    if (arrayList.isEmpty()) {
                        System.out.println("Array list is empty!");
                    } else {
                        System.out.println("Array list isnt empty!");
                    }
                    break;
                case 5:
                    System.out.println("Joining 2 Array lists, so enter them: ");
                    System.out.println("Enter List 1, enter \"done\" to stop entering");
                    list1 = new ArrayList<String>();
                    list1_input = new String();
                    while (!list1_input.equals("done")) {
                        list1_input = input.next();
                        if (!list1_input.equals("done")) {
                            list1.add(list1_input);
                        }
                    }
                    System.out.println("Enter List 2, enter \"done\" to stop entering");
                    list2 = new ArrayList<String>();
                    list2_input = new String();
                    while (!list2_input.equals("done")) {
                        list2_input = input.next();
                        if (!list2_input.equals("done")) {
                            list2.add(list2_input);
                        }
                    }
                    // merge 2 Arraylists
                    list1.addAll(list2);
                    System.out.println("Displaying all the elements");
                    for (String iterable_element : list1) {
                        System.out.println(iterable_element);
                    }
                    break;
                case 6:
                    System.out.println("Displaying all the elements");
                    for (String iterable_element : arrayList) {
                        System.out.println(iterable_element);
                    }
                    break;
                case 3:
                    System.out.println("Reversing the Elements of the List");
                    Collections.reverse(arrayList);
                    System.out.println("Displaying all the elements");
                    for (String iterable_element : arrayList) {
                        System.out.println(iterable_element);
                    }
                    break;
                case 7:
                    System.out.println("Quitting!");
                    System.exit(0);
                default:
                    break;
            }
        }
    }
}
