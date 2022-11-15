import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.io.*;

class Colors {
    static Color primaryColor = new Color(255, 255, 255); // text color
    static Color bgColor = new Color(27, 30, 52); // background
    static Color secondaryColor = new Color(44, 49, 70); // upper background
    static Color secondaryColorRollover = new Color(53, 59, 80); // upper background
    static Color accentColor = new Color(26, 122, 230); // Accent
}

class Numpad extends JPanel {
    Numpad() {

    }
}

class Operators_pnl extends JPanel {
    Operators_pnl() {

    }
}

// Main Calculator Frame no panels
class Calculator extends JFrame {
    JButton One;
    Numpad numpad;
    Operators_pnl operators_pnl;
    Font buttonFont;
    Calculator() {
        this.setTitle("Calculator");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setUndecorated(false);
        this.setPreferredSize(new Dimension(500, 500));
        this.getContentPane().setBackground(Colors.bgColor);
        this.setLayout(null);
        createFonts();
        createPanels();
        createButtons();
        this.add(One);
        this.pack();
        this.setVisible(true);
        this.setLocationRelativeTo(null);
    }

    public void createPanels() {
        numpad = new Numpad();
    }

    public void createButtons() {
        One = new JButton();
        One.setText("1");
        One.setBounds(50, 50, 60, 60);
        One.setFocusPainted(false);
        One.setContentAreaFilled(false);
        One.setOpaque(true);
        One.setBorder(null);
        One.setBackground(Colors.secondaryColor);
        One.setForeground(Colors.primaryColor);
        One.setFont(buttonFont);
        One.addChangeListener(evt -> {
            if (One.getModel().isPressed()) {
                One.setForeground(Colors.primaryColor);
                One.setBackground(Colors.secondaryColorRollover);
            } else if (One.getModel().isRollover()) {
                One.setForeground(Colors.accentColor);
                One.setBackground(Colors.secondaryColorRollover);
            } else {
                One.setForeground(Colors.primaryColor);
                One.setBackground(Colors.secondaryColor);
            }
        });
        // resize_btn.addActionListener(e -> {
        // if (!Main.maximized) {
        // this.setExtendedState(MAXIMIZED_BOTH);
        // resize_btn.setIcon(new ImageIcon(resizeDown_image));
        // } else {
        // this.setExtendedState(JFrame.NORMAL);
        // this.setLocationRelativeTo(null);
        // Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
        // int x = (int) ((dimension.getWidth() - Main.WIDTH) / 2);
        // int y = (int) ((dimension.getHeight() - Main.HEIGHT) / 2);
        // this.setBounds(x, y, Main.WIDTH, Main.HEIGHT);
        // resize_btn.setIcon(new ImageIcon(resizeUp_image));
        // }
        // Main.maximized = !Main.maximized;
        // });

    }

    public void createFonts() {
        try {
            buttonFont = Font.createFont(Font.TRUETYPE_FONT,
                    new File("./ProductSans-Light.ttf"))
                    .deriveFont(30f);
            GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
            // register the font
            ge.registerFont(buttonFont);

        } catch (FontFormatException | IOException e) {
            e.printStackTrace();
        }
    }
}

public class assignment_8 {
    static Calculator calc;

    public static void main(String[] args) {
        calc = new Calculator();
    }
}
