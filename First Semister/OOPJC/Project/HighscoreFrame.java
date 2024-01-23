package org.howmuch;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentEvent;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import static org.howmuch.Main.*;

public class HighscoreFrame extends JFrame {
    BackgroundPanel backgroundPanel;
    JButton backToMenu_btn;
    JTextArea highScores_txtArea;

    HighscoreFrame() {
        backgroundPanel = new BackgroundPanel();

        this.setTitle("How Much? ");
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
        createLabels();
        reassignColors();
        reassignBounds();

        this.addComponentListener(new ComponentAdapter() {
            @Override
            public void componentResized(ComponentEvent e) {
                reassignBounds();
                repaint();
            }
        });

        this.add(highScores_txtArea);
        this.add(backToMenu_btn);
        this.add(basicButtons_pnl);
        this.add(backgroundPanel);
        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    private void createLabels() {
        highScores_txtArea = new JTextArea();
        int peopleCount = 0;
        java.util.List<String[]> userData = DataBaseManager.getStoredUserScores();
        for (int i = 0; i < userData.size(); i++) {
            System.out.println(Integer.parseInt(userData.get(i)[2]));
        }
        ArrayList<Integer> scores = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < userData.size(); i++) {
            System.out.println(Integer.parseInt(userData.get(i)[2]));
            scores.add(Integer.parseInt(userData.get(i)[2]));
        }
        scores.sort(Collections.reverseOrder());

        for (int i = 0; i < scores.size(); i++) {
            System.out.println(Integer.parseInt(String.valueOf(scores.get(i))));
        }
        System.out.println("fianls");
        for (int i = 0; i < scores.size(); i++) {
            for (int j = 0; j < userData.size(); j++) {
                if (Integer.valueOf(userData.get(j)[2]).equals(scores.get(i))) {
                    System.out.println(Arrays.toString(userData.get(j)));
                    sb.append(userData.get(j)[0] + "   -   " + userData.get(j)[2] + "\n");
                    peopleCount++;
                    if (peopleCount == 5) {
                        break;
                    }
                }
            }
            if (peopleCount == 5) {
                break;
            }
        }
        highScores_txtArea.setText(String.valueOf(sb));
        highScores_txtArea.setAlignmentY(Box.CENTER_ALIGNMENT);
        highScores_txtArea.setAlignmentX(Box.LEFT_ALIGNMENT);
        highScores_txtArea.setOpaque(true);
        highScores_txtArea.setBorder(null);
        highScores_txtArea.setLineWrap(true);
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
        highScores_txtArea.setBounds((int) (0.60 * screenSize.getWidth()), (int) (0.38 * screenSize.getHeight()),
                (int) (0.60 * screenSize.getWidth()), 700);
        highScores_txtArea.setFont(textFont.deriveFont(44f));

    }

    private void reassignColors() {
        Colors.reassignColors();
        if (Colors.DarkMode) {
            backgroundPanel.setBackground("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/images/highscore dark.png");
        } else {
            backgroundPanel.setBackground("/run/media/krishnaraj/Programs/Java/How Much/src/main/resources/images/highscore.png");
        }
        backToMenu_btn.setBackground(Colors.primaryColor);
        backToMenu_btn.setForeground(Colors.bgColor);

        basicButtons_pnl.setBackground(Colors.bgColor);
        exit_btn.setBackground(Colors.bgColor);
        resize_btn.setBackground(Colors.bgColor);
        minimize_btn.setBackground(Colors.bgColor);
        highScores_txtArea.setBackground(Colors.bgColor);
        highScores_txtArea.setForeground(Colors.primaryColor);
    }

    private void createButtons() {
        backToMenu_btn = new JButton();
        backToMenu_btn.setText("Back to Menu");
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
    }
}
