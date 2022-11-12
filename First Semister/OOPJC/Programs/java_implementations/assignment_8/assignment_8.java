import javax.swing.*;
import java.awt.*;
import java.util.*;

// Main Calculator Frame no panels
class Calculator extends JFrame {
    JButton One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Equal_btn, Add_btn, Subtract_btn, Multiply_btn,
            Decimal_btn, Clear_btn;

    Calculator() {
        this.setTitle("Calculator");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setUndecorated(false);
        this.setMinimumSize(new Dimension(600, 700));
        this.setBackground(new Color(233, 166, 166));
        createButtons();
        this.add(One);
        this.pack();
        this.setVisible(true);
        this.setLocationRelativeTo(null);
    }

    public void createButtons() {
        One = new JButton();
        One.setText("1");
        // One.setBounds(50, 50, 40, 40);
        // One.setFocusPainted(false);
        // One.setContentAreaFilled(false);
        // One.setOpaque(true);
        // One.setBorder(null);
    }
}

public class assignment_8 {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
    }
}
