import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.util.List;
import java.io.*;

class Colors {
    static Color primaryColor = new Color(255, 255, 255); // text color
    static Color bgColor = new Color(27, 30, 52); // background
    static Color secondaryColor = new Color(44, 49, 70); // upper background
    static Color secondaryColorRollover = new Color(53, 59, 80); // upper background
    static Color accentColor = new Color(26, 122, 230); // Accent
}

class Numpad extends JPanel {
    JButton[] numbers = new JButton[12];

    Numpad() {
        this.setFocusable(true);
        this.setVisible(true);
        this.setBorder(null);
        this.setBounds(50, 150, 280, 380);
        this.setBackground(Colors.bgColor);
        this.setLayout(new GridLayout(4, 3, 15, 15));
        createButtons();
        for (int i = 0; i < numbers.length; i++) {
            this.add(numbers[i]);
        }
    }

    public void createButtons() {
        for (int i = 0; i < 12; i++) {
            numbers[i] = new JButton();
            numbers[i].setText(String.valueOf(i + 1));
            numbers[i].setFocusPainted(false);
            numbers[i].setContentAreaFilled(false);
            numbers[i].setOpaque(true);
            numbers[i].setBorder(null);
            numbers[i].setBackground(Colors.secondaryColor);
            numbers[i].setForeground(Colors.primaryColor);
            numbers[i].setFont(Calculator.buttonFont);
            final JButton temp = numbers[i];
            temp.addChangeListener(evt -> {
                if (temp.getModel().isPressed()) {
                    temp.setForeground(Colors.primaryColor);
                    temp.setBackground(Colors.secondaryColorRollover);
                } else if (temp.getModel().isRollover()) {
                    temp.setForeground(Colors.accentColor);
                    temp.setBackground(Colors.secondaryColorRollover);
                } else {
                    temp.setForeground(Colors.primaryColor);
                    temp.setBackground(Colors.secondaryColor);
                }
            });
            temp.addActionListener(e -> {
                System.out.println(((JButton) e.getSource()).getText());
                Calculator.display.setText(Calculator.display.getText() + ((JButton) e.getSource()).getText());
            });
        }
        numbers[9].setText("0");
        numbers[10].setText(".");
        numbers[11].setText("%");
    }
}

class Operators_pnl extends JPanel {
    static JButton[] operators = new JButton[4];
    static String currentOperator;

    Operators_pnl() {
        this.setFocusable(true);
        this.setVisible(true);
        this.setBorder(null);
        this.setBounds(345, 150, (int) 250 / 3, 380);
        this.setBackground(Colors.bgColor);
        this.setLayout(new GridLayout(4, 1, 0, 15));
        createButtons();
        for (int i = 0; i < operators.length; i++) {
            this.add(operators[i]);
        }
    }

    public void createButtons() {
        for (int i = 0; i < 4; i++) {
            operators[i] = new JButton();
            operators[i].setFocusPainted(false);
            operators[i].setContentAreaFilled(false);
            operators[i].setOpaque(true);
            operators[i].setBorder(null);
            operators[i].setBackground(Colors.secondaryColor);
            operators[i].setForeground(Colors.primaryColor);
            operators[i].setFont(Calculator.buttonFont);
            final JButton temp = operators[i];
            temp.addChangeListener(evt -> {
                if (temp.getModel().isPressed()) {
                    temp.setForeground(Colors.primaryColor);
                    temp.setBackground(Colors.secondaryColorRollover);
                } else if (temp.getModel().isRollover()) {
                    temp.setForeground(Colors.accentColor);
                    temp.setBackground(Colors.secondaryColorRollover);
                } else {
                    temp.setForeground(Colors.primaryColor);
                    temp.setBackground(Colors.secondaryColor);
                }
            });
            temp.addActionListener(e -> {
                if (!Calculator.operator_used) {
                    System.out.println(((JButton) e.getSource()).getText());
                    Calculator.display.setText(Calculator.display.getText() + ((JButton) e.getSource()).getText());
                    Calculator.operator_used = true;
                    operators[0].setEnabled(false);
                    operators[1].setEnabled(false);
                    operators[2].setEnabled(false);
                    operators[3].setEnabled(false);
                    currentOperator = ((JButton) e.getSource()).getText();
                }
            });
        }
        operators[0].setText("+");
        operators[1].setText("-");
        operators[2].setText("*");
        operators[3].setText("/");
    }
}

// Main Calculator Frame no panels
class Calculator extends JFrame {
    static double number_1, number_2;
    static boolean operator_used = false;
    JButton clearBtn, backspaceBtn, resultBtn;
    static JTextField display;
    Numpad numpad;
    Operators_pnl operators_pnl;
    static Font buttonFont;

    Calculator() {
        this.setTitle("Calculator");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setUndecorated(false);
        this.setPreferredSize(new Dimension(480, 670));
        this.getContentPane().setBackground(Colors.bgColor);
        this.setLayout(null);
        createFonts();
        createPanels();
        createButtons();
        this.add(display);
        this.add(numpad);
        this.add(operators_pnl);
        this.add(clearBtn);
        this.add(backspaceBtn);
        this.add(resultBtn);
        this.pack();
        this.setVisible(true);
        this.setLocationRelativeTo(null);
    }

    public void createPanels() {
        numpad = new Numpad();
        operators_pnl = new Operators_pnl();
    }

    public void createButtons() {
        display = new JTextField();
        display.setBounds(50, 50, 380, 80);
        display.setOpaque(true);
        display.setAlignmentX(RIGHT_ALIGNMENT);
        display.setBorder(null);
        display.setBackground(Colors.secondaryColor);
        display.setForeground(Colors.primaryColor);
        display.setFont(Calculator.buttonFont.deriveFont(55f));
        display.addActionListener(e -> {
            System.out.println(((JButton) e.getSource()).getText());
        });

        clearBtn = new JButton();
        clearBtn.setText("AC");
        clearBtn.setBounds(50 + 15 + (int) 250 / 3, 542, (int) 250 / 3, (int) 250 / 3);
        clearBtn.setFocusPainted(false);
        clearBtn.setContentAreaFilled(false);
        clearBtn.setOpaque(true);
        clearBtn.setBorder(null);
        clearBtn.setBackground(Colors.secondaryColor);
        clearBtn.setForeground(Colors.primaryColor);
        clearBtn.setFont(Calculator.buttonFont);
        clearBtn.addChangeListener(evt -> {
            if (clearBtn.getModel().isPressed()) {
                clearBtn.setForeground(Colors.primaryColor);
                clearBtn.setBackground(Colors.secondaryColorRollover);
            } else if (clearBtn.getModel().isRollover()) {
                clearBtn.setForeground(Colors.accentColor);
                clearBtn.setBackground(Colors.secondaryColorRollover);
            } else {
                clearBtn.setForeground(Colors.primaryColor);
                clearBtn.setBackground(Colors.secondaryColor);
            }
        });
        clearBtn.addActionListener(e -> {
            System.out.println(((JButton) e.getSource()).getText());
            display.setText("");
            operator_used = false;
            Operators_pnl.operators[0].setEnabled(true);
            Operators_pnl.operators[1].setEnabled(true);
            Operators_pnl.operators[2].setEnabled(true);
            Operators_pnl.operators[3].setEnabled(true);
        });

        backspaceBtn = new JButton();
        backspaceBtn.setText("DEL");
        backspaceBtn.setBounds(50, 542, (int) 250 / 3, (int) 250 / 3);
        backspaceBtn.setFocusPainted(false);
        backspaceBtn.setContentAreaFilled(false);
        backspaceBtn.setOpaque(true);
        backspaceBtn.setBorder(null);
        backspaceBtn.setBackground(Colors.secondaryColor);
        backspaceBtn.setForeground(Colors.primaryColor);
        backspaceBtn.setFont(Calculator.buttonFont);
        backspaceBtn.addChangeListener(evt -> {
            if (backspaceBtn.getModel().isPressed()) {
                backspaceBtn.setForeground(Colors.primaryColor);
                backspaceBtn.setBackground(Colors.secondaryColorRollover);
            } else if (backspaceBtn.getModel().isRollover()) {
                backspaceBtn.setForeground(Colors.accentColor);
                backspaceBtn.setBackground(Colors.secondaryColorRollover);
            } else {
                backspaceBtn.setForeground(Colors.primaryColor);
                backspaceBtn.setBackground(Colors.secondaryColor);
            }
        });
        backspaceBtn.addActionListener(e -> {
            System.out.println(((JButton) e.getSource()).getText());
            try {
                Character op_check = display.getText().charAt(display.getText().length() - 1);
                if (op_check == '+' || op_check == '-' || op_check == '*' || op_check == '/') {
                    operator_used = false;
                    Operators_pnl.operators[0].setEnabled(true);
                    Operators_pnl.operators[1].setEnabled(true);
                    Operators_pnl.operators[2].setEnabled(true);
                    Operators_pnl.operators[3].setEnabled(true);
                }
                display.setText(display.getText().substring(0, display.getText().length() - 1));
            } catch (Exception f) {
                System.out.println("You got nothing on screen then how can you delete? ");
            }
        });

        resultBtn = new JButton();
        resultBtn.setText("=");
        resultBtn.setBounds(245, 542, (int) 184, (int) 250 / 3);
        resultBtn.setFocusPainted(false);
        resultBtn.setContentAreaFilled(false);
        resultBtn.setOpaque(true);
        resultBtn.setBorder(null);
        resultBtn.setBackground(Colors.secondaryColor);
        resultBtn.setForeground(Colors.primaryColor);
        resultBtn.setFont(Calculator.buttonFont);
        resultBtn.addChangeListener(evt -> {
            if (resultBtn.getModel().isPressed()) {
                resultBtn.setForeground(Colors.primaryColor);
                resultBtn.setBackground(Colors.secondaryColorRollover);
            } else if (resultBtn.getModel().isRollover()) {
                resultBtn.setForeground(Colors.accentColor);
                resultBtn.setBackground(Colors.secondaryColorRollover);
            } else {
                resultBtn.setForeground(Colors.primaryColor);
                resultBtn.setBackground(Colors.secondaryColor);
            }
        });
        resultBtn.addActionListener(e -> {
            System.out.println(((JButton) e.getSource()).getText());
            System.out.println(display.getText().split(Operators_pnl.currentOperator)[0]);
            int a = Integer.parseInt(display.getText().split(Operators_pnl.currentOperator)[0]);
            int b = Integer.parseInt(display.getText().split(Operators_pnl.currentOperator)[1]);
            System.out.println(a);
            int c = 0;
            try {
                switch (Operators_pnl.currentOperator) {
                    case "+":
                        c = a + b;
                        System.out.println(c);
                        break;
                    case "*":
                        c = a * b;
                        System.out.println(c);
                        break;
                    case "-":
                        c = a - b;
                        System.out.println(c);
                        break;
                    case "/":
                        c = a / b;
                        System.out.println(c);
                        break;
                    default:
                        break;
                }
            } catch (Exception f) {
                System.out.println(f.getMessage());
                display.setText("");
                operator_used = false;
                Operators_pnl.operators[0].setEnabled(true);
                Operators_pnl.operators[1].setEnabled(true);
                Operators_pnl.operators[2].setEnabled(true);
                Operators_pnl.operators[3].setEnabled(true);
            }
            display.setText(String.valueOf(c));
            operator_used = false;
            Operators_pnl.operators[0].setEnabled(true);
            Operators_pnl.operators[1].setEnabled(true);
            Operators_pnl.operators[2].setEnabled(true);
            Operators_pnl.operators[3].setEnabled(true);
        });
    }

    public static void createFonts() {
        try {
            buttonFont = Font.createFont(Font.TRUETYPE_FONT,
                    new File("./Calculator.ttf"))
                    .deriveFont(45f);
            // buttonFont = Font.createFont(Font.TRUETYPE_FONT,
            //         new File("./ProductSans-Light.ttf"))
            //         .deriveFont(35f);
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
