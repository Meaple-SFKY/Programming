package com.principle.parser;
 
import javax.swing.JFrame;
 
public class Demo {
    public static void main(String[] args) {
        MyFrame frame = new MyFrame("Parser");
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setSize(600, 200);
                frame.setVisible(true);
			}
        });
	}
}

