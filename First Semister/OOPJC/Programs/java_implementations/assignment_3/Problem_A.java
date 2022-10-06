package assignment_3;

import java.lang.Math;

public class Problem_A {
    public static void main(String[] args) {
        Shapes circle = new Shapes(7);
        Shapes square = new Shapes(1.5);
        Shapes rectangle = new Shapes(1.4, 3.5);
        System.out.println("The Radius of the Circle is: " + circle.radius);
        System.out.println("The Area of the Circle is: " + circle.Area(circle.radius));
        System.out.println("The Side of the Square is: " + square.side);
        System.out.println("The Area of the Square is: " + square.Area(square.side));
        System.out.println("The Length of the Rectangle is: " + rectangle.length);
        System.out.println("The Breadth of the Rectangle is: " + rectangle.breadth);
        System.out.println("The Area of the Rectangle is: "
                + String.format("%.2f", rectangle.Area(rectangle.length, rectangle.breadth)));
    }
}