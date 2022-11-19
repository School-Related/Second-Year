// Krishnaraj Thadesar
// Batch A1, PA20
// OOPCJ Assignment 9
// Write a Java applet program that displays a simple message in centre of the screen.


import java.applet.*;
import java.awt.*;

public class Assignment_9 extends Applet {
    public void print(Graphics g) {
        g.drawString("Welcome to Java Applets in Assignment 9", 150, 150);
    }
}