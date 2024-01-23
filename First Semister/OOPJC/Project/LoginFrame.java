
/*
 * This is the loginFrame file, which is one of the first classes that comes into picture, pun intended. 
 * It does everything it can to make it look like the login screen of a modern website like google. Even goes as far as to use the same fonts. 
 * It checks the username and the password entered by the user, and matches it with the csv file it has. And reports the situation on screen. 
 * Once the user is justified and logged in, or has created a new account, it adds them, assigns some basic variables, and then Calls the Main Menu class by calling the changeFrame function in the Main class. 
 */

package org.howmuch;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

// Basically importing every static thing from Main coz its used so often
// not a very good practice. 
import static org.howmuch.Main.*;

public class LoginFrame extends JFrame implements Runnable {

    public static boolean running = true, userExists = false, incorrectPassword = false, newUser = false;
    JLabel username_lbl, password_lbl, background_lbl, status_lbl, status_emoji_lbl;
    JButton login_btn, guest_btn, newAccount_btn, exit_btn, resize_btn, minimize_btn;
    JTextField username_txt_fld;
    JPasswordField password_txt_fld;
    Thread loginThread;

    /*
     * This is the standard implmentation of a constructor in this game. There are
     * some basic attributes of the Frame calsses that it extends from
     * And then sets them. It then creates the things you are supposed to create in
     * the GUI, and then adds them to the frame. This could be done in a panel, yes,
     * but then you couldnt use some things like the CompoenentListener class that
     * only listens to the Frame mainly, and that helps in calling certain functions
     * when you resize the screen.
     */
    LoginFrame() {
        this.setTitle("How Much? ");
        this.setResizable(false);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        createFonts();
        createButtons();
        createLabels();
        createTextFields();

        this.add(status_lbl);
        this.add(status_emoji_lbl);
        this.add(login_btn);
        this.add(username_lbl);
        this.add(password_lbl);
        this.add(guest_btn);
        this.add(newAccount_btn);
        this.add(exit_btn);
        this.add(minimize_btn);
        this.add(username_txt_fld);
        this.add(password_txt_fld);
        this.add(background_lbl);

        // Thread to check the password entered by the user every 2 seconds is invoked
        // by this thread's start method.
        startThread();

        this.pack();
        this.setVisible(true);
        this.setLocationRelativeTo(null); // put in the center.
    }

    /*
     * Standard function to create buttons and assign their attributes. As some
     * lines are dupiliated, they certainly can be extracted as separete methods
     * themselves.
     */
    public void createButtons() {
        login_btn = new JButton();
        login_btn.setText("Login");
        login_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        login_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        login_btn.setBounds(775, 532, 200, 40);
        login_btn.setFont(textFont.deriveFont(44f));
        login_btn.setFocusPainted(false);
        login_btn.setContentAreaFilled(false);
        login_btn.setOpaque(true);
        login_btn.setBorder(null);

        login_btn.setBackground(Colors.bgColor);

        // To control what happens when the mouse interacts with this button.
        login_btn.addChangeListener(evt -> {
            if (login_btn.getModel().isPressed()) {
                login_btn.setForeground(Colors.primaryColor);
            } else if (login_btn.getModel().isRollover()) {
                login_btn.setForeground(Colors.secondaryColor);
            } else {
                login_btn.setForeground(Colors.primaryColor);
            }
        });

        // Stuff to do when it is pressed. Applicable to all buttons here.
        login_btn.addActionListener(e -> {
            if (DataBaseManager.doesUsernameExist(username_txt_fld.getText())) {

                // Now the user is trying to login, so we check if the password matches
                // if it does, then we assign some basic variables, and close this screen, open
                // the menu screen.
                if (DataBaseManager.doesPasswordMatch(username_txt_fld.getText(),
                        String.valueOf(password_txt_fld.getPassword()))) {
                    DataBaseManager.currentUsername = username_txt_fld.getText();
                    DataBaseManager.currentPassword = String.valueOf(password_txt_fld.getPassword());
                    this.setVisible(false);
                    this.dispose();
                    running = false;
                    grantAccess = true;
                    Main.changeFrame(1);
                } else {
                    grantAccess = false;
                    incorrectPassword = true;
                }
            } else {
                // If the user has entered a username and a password, and he doesnt exist, then
                // clearly is a new user.
                newUser = true;
            }

        });
        login_btn.setEnabled(false);

        guest_btn = new JButton();
        guest_btn.setText("Guest");
        guest_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        guest_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        guest_btn.setBounds(940, 532, 200, 40);
        guest_btn.setFont(textFont.deriveFont(44f));
        guest_btn.setFocusPainted(false);
        guest_btn.setContentAreaFilled(false);
        guest_btn.setOpaque(true);
        guest_btn.setBorder(null);
        guest_btn.setBackground(Colors.bgColor);
        guest_btn.addChangeListener(evt -> {
            if (guest_btn.getModel().isPressed()) {
                guest_btn.setForeground(Colors.primaryColor);
            } else if (guest_btn.getModel().isRollover()) {
                guest_btn.setForeground(Colors.secondaryColor);
            } else {
                guest_btn.setForeground(Colors.primaryColor);
            }
        });
        guest_btn.addActionListener(e -> {
            Main.isGuest = true;
            DataBaseManager.currentPassword = "guest";
            DataBaseManager.currentUsername = "guest";
            this.setVisible(false);
            this.dispose();
            running = false;
            grantAccess = true;
            Main.changeFrame(1);
        });

        newAccount_btn = new JButton();
        newAccount_btn.setText("Create New Account");
        newAccount_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        newAccount_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        newAccount_btn.setBounds(615, 590, 800, 40);
        newAccount_btn.setFont(textFont.deriveFont(44f));
        newAccount_btn.setFocusPainted(false);
        newAccount_btn.setContentAreaFilled(false);
        newAccount_btn.setOpaque(true);
        newAccount_btn.setBorder(null);
        newAccount_btn.setBackground(Colors.bgColor);
        newAccount_btn.addChangeListener(evt -> {
            if (newAccount_btn.getModel().isPressed()) {
                newAccount_btn.setForeground(Colors.primaryColor);
            } else if (newAccount_btn.getModel().isRollover()) {
                newAccount_btn.setForeground(Colors.secondaryColor);
            } else {
                newAccount_btn.setForeground(Colors.primaryColor);
            }
        });

        newAccount_btn.addActionListener(e -> {
            Main.isGuest = false;
            if (!DataBaseManager.doesUsernameExist(username_txt_fld.getText())) {
                DataBaseManager.currentUsername = username_txt_fld.getText();
                DataBaseManager.currentPassword = String.valueOf(password_txt_fld.getPassword());
                DataBaseManager.currentScore = 0;
                DataBaseManager.addNewUser();
                running = false;
                this.setVisible(false);
                this.dispose();
                grantAccess = true;
                Main.changeFrame(1);
            } else {
                System.out.println("User Already Exists");
                userExists = true;
            }
        });
        newAccount_btn.setEnabled(false);

        ImageIcon exit = new ImageIcon("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/icons/circle_delete.png");
        Image exit_image = exit.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        ImageIcon minimize = new ImageIcon("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/icons/circle_minus.png");
        Image minimize_image = minimize.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);
        ImageIcon resize = new ImageIcon("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/icons/screen_expand_3.png");
        Image resize_image = resize.getImage().getScaledInstance(25, 25, Image.SCALE_SMOOTH);

        exit_btn = new JButton();
        // exit_btn.setText("-");
        exit_btn.setIcon(new ImageIcon(exit_image));
        exit_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        exit_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        exit_btn.setBounds(1230, 15, 25, 25);
        exit_btn.setFont(textFont.deriveFont(44f));
        exit_btn.setFocusPainted(false);
        exit_btn.setContentAreaFilled(false);
        exit_btn.setOpaque(true);
        exit_btn.setBorder(null);
        exit_btn.setBackground(Colors.bgColor);
        exit_btn.addChangeListener(evt -> {
            if (exit_btn.getModel().isPressed()) {
                exit_btn.setForeground(Colors.primaryColor);
                this.setVisible(false);
                this.dispose();
                running = false;
                Main.changeFrame(0);
            } else if (exit_btn.getModel().isRollover()) {
                exit_btn.setForeground(Colors.secondaryColor);
            } else {
                exit_btn.setForeground(Colors.primaryColor);
            }
        });

        resize_btn = new JButton();
        resize_btn.setIcon(new ImageIcon(resize_image));
        resize_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        resize_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        resize_btn.setBounds(1195, 15, 25, 25);
        resize_btn.setFont(textFont.deriveFont(44f));
        resize_btn.setFocusPainted(false);
        resize_btn.setContentAreaFilled(false);
        resize_btn.setOpaque(true);
        resize_btn.setBorder(null);
        resize_btn.setBackground(Colors.bgColor);
        resize_btn.addChangeListener(evt -> {
            if (exit_btn.getModel().isPressed()) {
                this.setExtendedState(JFrame.MAXIMIZED_BOTH);
                exit_btn.setForeground(Colors.primaryColor);
            } else if (exit_btn.getModel().isRollover()) {
                exit_btn.setForeground(Colors.secondaryColor);
            } else {
                exit_btn.setForeground(Colors.primaryColor);
            }
        });

        minimize_btn = new JButton();
        // minimize_btn.setText("-");
        minimize_btn.setIcon(new ImageIcon(minimize_image));
        minimize_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        minimize_btn.setAlignmentX(Box.CENTER_ALIGNMENT);
        minimize_btn.setBounds(1195, 15, 25, 25);
        minimize_btn.setFont(textFont.deriveFont(44f));
        minimize_btn.setFocusPainted(false);
        minimize_btn.setContentAreaFilled(false);
        minimize_btn.setOpaque(true);
        minimize_btn.setBorder(null);
        minimize_btn.setBackground(Colors.bgColor);
        minimize_btn.addChangeListener(evt -> {
            if (minimize_btn.getModel().isPressed()) {
                this.setState(JFrame.ICONIFIED);
                minimize_btn.setForeground(Colors.primaryColor);
            } else if (minimize_btn.getModel().isRollover()) {
                minimize_btn.setForeground(Colors.secondaryColor);
            } else {
                minimize_btn.setForeground(Colors.primaryColor);
            }
        });

    }

    /*
     * Standard function to create labels used in this frame.
     */
    public void createLabels() {
        ImageIcon icon = new ImageIcon("src/main/resources/images/Login_bg.png");
        Image bg_image = icon.getImage().getScaledInstance(1280, 720, Image.SCALE_SMOOTH);

        background_lbl = new JLabel();
        background_lbl.setIcon(new ImageIcon(bg_image));

        username_lbl = new JLabel();
        username_lbl.setText("Enter Username");
        username_lbl.setFont(textFont.deriveFont(44f));
        username_lbl.setAlignmentX(Box.CENTER_ALIGNMENT);
        username_lbl.setBounds(822, 244, 800, 80);
        username_lbl.setForeground(Colors.primaryColor);

        password_lbl = new JLabel();
        password_lbl.setText("Password");
        password_lbl.setFont(textFont.deriveFont(44f));
        password_lbl.setAlignmentX(Box.CENTER_ALIGNMENT);
        password_lbl.setBounds(822, 340, 800, 150);
        password_lbl.setForeground(Colors.primaryColor);

        status_lbl = new JLabel();
        status_lbl.setText("");
        status_lbl.setFont(password_font.deriveFont(30f).deriveFont(Font.ITALIC));
        status_lbl.setAlignmentX(Box.CENTER_ALIGNMENT);
        status_lbl.setBounds(30, 580, 800, 40);
        status_lbl.setForeground(Colors.bgColor);

        status_emoji_lbl = new JLabel();
        status_emoji_lbl.setText("");
        status_emoji_lbl.setFont(emoji_font.deriveFont(50f));
        status_emoji_lbl.setAlignmentX(Box.CENTER_ALIGNMENT);
        status_emoji_lbl.setBounds(25, 500, 80, 80);
        status_emoji_lbl.setForeground(Colors.bgColor);
    }

    /*
     * Standard function to create Text Fields.
     */
    public void createTextFields() {
        username_txt_fld = new JTextField("");
        username_txt_fld.setFont(password_font);
        username_txt_fld.setBounds(822, 319, 300, 50);
        username_txt_fld.setBackground(Colors.bgColor);
        username_txt_fld.setOpaque(true);
        username_txt_fld.setBorder(null);
        username_txt_fld.setForeground(Colors.accentColor);
        username_txt_fld.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println(username_txt_fld.getText());
            }
        });

        password_txt_fld = new JPasswordField("");
        password_txt_fld.setFont(password_font);
        password_txt_fld.setBounds(822, 452, 300, 50);
        password_txt_fld.setBackground(Colors.bgColor);
        password_txt_fld.setOpaque(true);
        password_txt_fld.setBorder(null);
        password_txt_fld.setEchoChar('*');
        password_txt_fld.setForeground(Colors.accentColor);
        password_txt_fld.setAlignmentY(Box.CENTER_ALIGNMENT);
    }

    /*
     * This function is what checks the password, and so naturally has a lot of if
     * statements.
     * Most of them are self explanatory.
     */
    @Override
    public void run() {
        long lastTime = System.nanoTime();
        double amountOfTicks = 5.00;
        double ns = 1000000000 / amountOfTicks;
        double delta = 0;

        while (running) {
            // basic game loop logic to ensure 60 fps, dont think too much about it, it
            // makes sense.
            // you can reuse it for consistancy, or make a new one.

            long now = System.nanoTime();
            delta += (now - lastTime) / ns;
            lastTime = now;

            if (delta >= 1) {
                // System.out.println(username_txt_fld.getText());
                // System.out.println(password_txt_fld.getPassword());
                if (username_txt_fld.getText().length() == 0) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Enter Username & Password");
                    status_emoji_lbl.setText("\uD83E\uDEE3");
                    // status_emoji_lbl.setText("");
                } else if (newUser) {
                    status_lbl.setText("Welcome! Create New Account");
                    status_emoji_lbl.setText("\uD83D\uDE4F");
                    // status_emoji_lbl.setText("\uD83D\uDE1E");
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    newUser = false;
                } else if (incorrectPassword) {
                    status_lbl.setText("Password doesn't Match!");
                    status_emoji_lbl.setText("\uD83D\uDE16");
                    // status_emoji_lbl.setText("\uD83D\uDE1E");
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    incorrectPassword = false;
                } else if (userExists) {
                    status_lbl.setText("User Already Exists, Try to Login");
                    status_emoji_lbl.setText("\uD83D\uDE15");
                    try {
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    userExists = false;
                } else if (password_txt_fld.getPassword().length < 8) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Nope, Password is too Short");
                     status_emoji_lbl.setText("\uD83D\uDE0F");
                    // status_emoji_lbl.setText("\uD83E\uDD0F");
//                    status_emoji_lbl.setText("\uD83D\uDE15");
                } else if (Arrays.equals(password_txt_fld.getPassword(), "abcdefgh".toCharArray())) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Anyone can guess that bruh");
                    status_emoji_lbl.setText("\uD83D\uDC80");
                } else if (Arrays.equals(password_txt_fld.getPassword(), "12345678".toCharArray())) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("12345678? Really?");
                    status_emoji_lbl.setText("\uD83E\uDEE0");
                } else if (Arrays.equals(password_txt_fld.getPassword(), "asdfghjk".toCharArray())) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Be Lazy, but not thaaat lazy");
                    // status_emoji_lbl.setText("\uD83D\uDE42");
                    status_emoji_lbl.setText("\uD83D\uDC80");
                } else if (Arrays.equals(password_txt_fld.getPassword(), "asdfasdf".toCharArray())) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Even Krishnaraj isnt this lazy");
                    // status_emoji_lbl.setText("\uD83E\uDD21");
                    status_emoji_lbl.setText("\uD83D\uDC80");
                } else if (password_txt_fld.getPassword().length > 30) {
                    newAccount_btn.setEnabled(false);
                    status_lbl.setText("Woah, Its too big");
                    status_emoji_lbl.setText("\uD83D\uDE0F");
                } else {
                    status_lbl.setText("All Good!");
                    status_emoji_lbl.setText("\uD83D\uDC4C");
                    // status_emoji_lbl.setText("\uD83D\uDE0E" );
                    // status_emoji_lbl.setText("" );
                    newAccount_btn.setEnabled(true);
                    login_btn.setEnabled(true);
                }
                delta--;
            }

        }
    }

    public void startThread() {

        // Creating the Game Thread
        loginThread = new Thread(this);
        loginThread.start();

    }
}
