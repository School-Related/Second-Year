package org.howmuch;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import static org.howmuch.Main.*;

public class TopicsFrame extends JFrame {

    BackgroundPanel backgroundPanel;
    JButton option1_btn, option2_btn, option3_btn, option4_btn;
    JButton backToMenu_btn;
    JPanel options_panel;

    TopicsFrame() {
        backgroundPanel = new BackgroundPanel();

        this.setTitle("How Much?");
        if (maximized) {
            this.setExtendedState(MAXIMIZED_BOTH);
        } else {
            this.setPreferredSize(new Dimension(Main.WIDTH, Main.HEIGHT));
        }
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(true);
        this.setUndecorated(true);
        this.setMinimumSize(new Dimension(1280, 720));

        createFonts();
        createBasicButtonPanel();
        createButtons();
        createPanels();
        reassignColors();
        reassignBounds();

        this.addComponentListener(new ComponentAdapter() {
            @Override
            public void componentResized(ComponentEvent e) {
                reassignBounds();
                repaint();
            }
        });

        this.add(backToMenu_btn);
        this.add(options_panel);
        this.add(basicButtons_pnl);
        this.add(backgroundPanel);
        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    private void reassignBounds() {
        Dimension screenSize = this.getSize();

        // The back to menu mode label
        backToMenu_btn.setBounds((int) (0.015 * screenSize.getWidth()), (int) (0.80 * screenSize.getHeight()),
                (int) (0.20 * screenSize.getWidth()), (int) (0.07 * screenSize.getHeight()));
        backToMenu_btn.setFont(buttonFont.deriveFont((float) (0.05 * getHeight())));

        // The Entire basic button panel for closing minimizing and stuff
        basicButtons_pnl.setBounds(this.getWidth() - (exit_btn.getWidth() * 3) - 40, 10, exit_btn.getWidth() * 3 + 35,
                exit_btn.getHeight());

        // Options panel
        options_panel.setBounds((int) (0.60 * screenSize.getWidth()), (int) (0.34 * screenSize.getHeight()),
                (int) (0.45 * screenSize.getWidth()), 700);

        // Buttons in the Options Panel
        option1_btn.setBounds(new Rectangle((int) (0.45 * screenSize.getWidth()), 80));
        option1_btn.setFont(buttonFont.deriveFont((float) (0.07 * getHeight())));

        option2_btn.setBounds(new Rectangle((int) (0.45 * screenSize.getWidth()), 80));
        option2_btn.setFont(buttonFont.deriveFont((float) (0.07 * getHeight())));

        option3_btn.setBounds(new Rectangle((int) (0.45 * screenSize.getWidth()), 70));
        option3_btn.setFont(buttonFont.deriveFont((float) (0.07 * getHeight())));

        option4_btn.setBounds(new Rectangle((int) (0.45 * screenSize.getWidth()), 70));
        option4_btn.setFont(buttonFont.deriveFont((float) (0.07 * getHeight())));
    }

    private void reassignColors() {

        if (Colors.DarkMode) {
            backgroundPanel.setBackground("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/images/choose topic dark.png");
        } else {
            backgroundPanel.setBackground("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/images/choose topic.png");
        }
        Colors.reassignColors();
        basicButtons_pnl.setBackground(Colors.bgColor);
        exit_btn.setBackground(Colors.bgColor);
        resize_btn.setBackground(Colors.bgColor);
        backToMenu_btn.setBackground(Colors.primaryColor);
        backToMenu_btn.setForeground(Colors.bgColor);
        minimize_btn.setBackground(Colors.bgColor);
        option1_btn.setBackground(Colors.bgColor);
        option1_btn.setForeground(Colors.primaryColor);
        option2_btn.setBackground(Colors.bgColor);
        option2_btn.setForeground(Colors.primaryColor);
        option4_btn.setBackground(Colors.bgColor);
        option4_btn.setForeground(Colors.primaryColor);
        option3_btn.setBackground(Colors.bgColor);
        option3_btn.setForeground(Colors.primaryColor);
    }

    private void createPanels() {
        options_panel = new JPanel();
        BoxLayout bl = new BoxLayout(options_panel, BoxLayout.Y_AXIS);
        options_panel.setLayout(bl);
        options_panel.add(option1_btn);
        options_panel.add(Box.createRigidArea(new Dimension(0, 25)));
        options_panel.add(option2_btn);
        options_panel.add(Box.createRigidArea(new Dimension(0, 25)));
        options_panel.add(option3_btn);
        options_panel.add(Box.createRigidArea(new Dimension(0, 25)));
        options_panel.add(option4_btn);
        options_panel.setBackground(new Color(0, 0, 0, 0));

    }

    private void createButtons() {

        // Removing Change and Action Listeners.
        GameFrame.removeAllChangeAndActionListenersFromBasicButtons();

        exit_btn.addChangeListener(evt -> {
            if (exit_btn.getModel().isPressed()) {
                exit_btn.setForeground(Colors.primaryColor);
                Main.changeFrame(0);
            } else if (exit_btn.getModel().isRollover()) {
                exit_btn.setForeground(Colors.secondaryColor);
            } else {
                exit_btn.setForeground(Colors.primaryColor);
            }
        });
        resize_btn.addActionListener(e -> {
            if (!Main.maximized) {
                this.setExtendedState(MAXIMIZED_BOTH);
                resize_btn.setIcon(new ImageIcon(resizeDown_image));
            } else {
                this.setExtendedState(JFrame.NORMAL);
                this.setLocationRelativeTo(null);
                Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
                int x = (int) ((dimension.getWidth() - Main.WIDTH) / 2);
                int y = (int) ((dimension.getHeight() - Main.HEIGHT) / 2);
                this.setBounds(x, y, Main.WIDTH, Main.HEIGHT);
                resize_btn.setIcon(new ImageIcon(resizeUp_image));
            }
            Main.maximized = !Main.maximized;
        });

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

        backToMenu_btn = new JButton();
        backToMenu_btn.setText("Back to Menu ");
        backToMenu_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        backToMenu_btn.setAlignmentX(Box.LEFT_ALIGNMENT);
        backToMenu_btn.setFocusPainted(false);
        backToMenu_btn.setContentAreaFilled(false);
        backToMenu_btn.setOpaque(true);
        backToMenu_btn.setBorder(null);
        backToMenu_btn.addChangeListener(evt -> {
            if (backToMenu_btn.getModel().isPressed()) {
                backToMenu_btn.setForeground(Colors.bgColor);
            } else if (backToMenu_btn.getModel().isRollover()) {
                backToMenu_btn.setForeground(Colors.accentColor);
            } else {
                backToMenu_btn.setForeground(Colors.bgColor);
            }
        });
        backToMenu_btn.addActionListener(e -> {
            this.setVisible(false);
            this.dispose();
            grantAccess = true;
            Main.changeFrame(1);
        });

        option1_btn = new JButton();
        option1_btn.setText(Topics[0] + " ");
        option1_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        option1_btn.setAlignmentX(Box.LEFT_ALIGNMENT);
        option1_btn.setFocusPainted(false);
        option1_btn.setBounds(0, 0, 500, 500);
        option1_btn.setContentAreaFilled(false);
        option1_btn.setOpaque(true);
        option1_btn.setBorder(null);
        option1_btn.addChangeListener(evt -> {
            if (option1_btn.getModel().isPressed()) {
                option1_btn.setForeground(Colors.accentColor);
            } else if (option1_btn.getModel().isRollover()) {
                option1_btn.setForeground(Colors.accentColor);
            } else {
                option1_btn.setForeground(Colors.primaryColor);
            }
        });

        option1_btn.addActionListener(e -> {
            grantAccess = true;
            currentTopic = Topics[0];
            this.setVisible(false);
            this.dispose();
            grantAccess = true;
            Main.changeFrame(6);
        });

        option2_btn = new JButton();
        option2_btn.setText(Topics[1] + " ");
        option2_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        option2_btn.setAlignmentX(Box.LEFT_ALIGNMENT);
        option2_btn.setFocusPainted(false);
        option2_btn.setContentAreaFilled(false);
        option2_btn.setOpaque(true);
        option2_btn.setBorder(null);
        option2_btn.addChangeListener(evt -> {
            if (option2_btn.getModel().isPressed()) {
                option2_btn.setForeground(Colors.accentColor);
            } else if (option2_btn.getModel().isRollover()) {
                option2_btn.setForeground(Colors.accentColor);
            } else {
                option2_btn.setForeground(Colors.primaryColor);
            }
        });
        option2_btn.addActionListener(e -> {
            grantAccess = true;
            currentTopic = Topics[1];
            this.setVisible(false);
            this.dispose();
            grantAccess = true;
            Main.changeFrame(6);
        });

        option3_btn = new JButton();
        option3_btn.setText(Topics[2] + " ");
        option3_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        option3_btn.setAlignmentX(Box.LEFT_ALIGNMENT);
        option3_btn.setFocusPainted(false);
        option3_btn.setContentAreaFilled(false);
        option3_btn.setOpaque(true);
        option3_btn.setBorder(null);
        option3_btn.addChangeListener(evt -> {
            if (option3_btn.getModel().isPressed()) {
                option3_btn.setForeground(Colors.accentColor);
            } else if (option3_btn.getModel().isRollover()) {
                option3_btn.setForeground(Colors.accentColor);
            } else {
                option3_btn.setForeground(Colors.primaryColor);
            }
        });
        option3_btn.addActionListener(e -> {
            grantAccess = true;
            currentTopic = Topics[2];
            this.setVisible(false);
            this.dispose();
            grantAccess = true;
            Main.changeFrame(6);
        });

        option4_btn = new JButton();
        option4_btn.setText(Topics[3] + " ");
        option4_btn.setAlignmentY(Box.CENTER_ALIGNMENT);
        option4_btn.setAlignmentX(Box.LEFT_ALIGNMENT);
        option4_btn.setFont(buttonFont.deriveFont(44f));
        option4_btn.setFocusPainted(false);
        option4_btn.setContentAreaFilled(false);
        option4_btn.setOpaque(true);
        option4_btn.setBorder(null);
        option4_btn.addChangeListener(evt -> {
            if (option4_btn.getModel().isPressed()) {
                option4_btn.setForeground(Colors.accentColor);
            } else if (option4_btn.getModel().isRollover()) {
                option4_btn.setForeground(Colors.accentColor);
            } else {
                option4_btn.setForeground(Colors.primaryColor);
            }
        });
        option4_btn.addActionListener(e -> {
            grantAccess = true;
            currentTopic = Topics[3];
            this.setVisible(false);
            this.dispose();
            grantAccess = true;
            Main.changeFrame(6);
        });
    }

}
