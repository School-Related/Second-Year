import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class Main extends JFrame {
		Main() {
		JLabel lbl = new JLabel("Welcome to MITWPU, Pune");
		lbl.setFont(new Font ("Ariel", Font.ITALIC, 15));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // setting close operation.
		lbl.setBounds(50, 0, 500, 100);
		setLayout(null); // setting layout using FlowLayout object
		setSize(300, 150); // setting size of Jframe
		add(lbl); // adding Yes button to frame.
		setVisible(true);
	}

	
	public static void main(String[] args) {
		new Main();
	}
}