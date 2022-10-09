// Create a parent class Hillstations with the methods location() and famousfor().
// Create three subclasses by hill station names e.g. Manali, Shimla etc.
// Subclasses extend the superclass and override methods location() and famousfor().
// Call the methods location() and famousfor() by the Parent class, i.e. Hillstations
// class.
// It should refer to the base class object and the base class method overrides the
// superclass method, base class method is invoked at runtime.

package assignment_3;

public class Problem_B {
    public static void main(String[] args) {
        Manali obj = new Manali();
        obj.location();
        obj.famousfor();

        Shimla obj1 = new Shimla();
        obj1.location();
        obj1.famousfor();

        Mahabaleshwar obj2 = new Mahabaleshwar();
        obj2.location();
        obj2.famousfor();
    }
}
