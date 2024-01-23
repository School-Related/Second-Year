package org.howmuch;

import javax.swing.*;
import java.awt.*;

public class BackgroundPanel extends JPanel {
    private Image background;

    public void paintComponent(Graphics g) {

        super.paintComponent(g);
        int width = this.getSize().width;
        int height = this.getSize().height;

        if (this.background != null) {
            // Add the size of the window in drawImage method()
            g.drawImage(this.background, 0, 0, width, height, null);
        }
    }

    public void setBackground(String imagePath) {
        // Simply sets the background as the one that you have provided. It needs to be
        // a png file (I think)
        this.background = new ImageIcon(imagePath).getImage();
        repaint();
    }

}
