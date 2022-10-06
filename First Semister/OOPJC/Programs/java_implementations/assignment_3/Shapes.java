package assignment_3;

public class Shapes {

    public double Area;
    public double side;
    public double length;
    public double breadth;
    public int radius;

    Shapes(int radius) {
        Area = 0.0;
        this.radius = radius;
    }

    Shapes(double length, double breadth) {
        Area = 0.0;
        this.length = length;
        this.breadth = breadth;
    }

    Shapes(double side) {
        Area = 0.0;
        this.side = side;
    }

    double Area(int radius) {
        Area = 3.14 * radius * radius;
        return Area;
    }

    double Area(double length, double breadth) {
        Area = length * breadth;
        return Area;
    }

    double Area(double side) {
        Area = side * side;
        return Area;
    }

}
