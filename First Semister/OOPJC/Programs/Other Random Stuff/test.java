import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class test extends JFrame {

    test() {
        JButton bt1 = new JButton("no"); // Creating a Yes Button.
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // setting close operation.
        bt1.setBounds(60, 50, 500, 500);
        ImageIcon imageIcon = new ImageIcon("../../Lab/pic.jpg");
        bt1.setIcon(imageIcon);
        setLayout(null); // setting layout using FlowLayout object
        setSize(700, 700); // setting size of Jframe
        add(bt1); // adding Yes button to frame.
        setVisible(true);
    }

    public static void main(String[] args) {
        new test();
    }
}