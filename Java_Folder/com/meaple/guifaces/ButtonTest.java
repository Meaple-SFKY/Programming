package com.meaple.guifaces;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ButtonTest {
    public static void main(String[] args) {
        ButtonFrame buttonFrame = new ButtonFrame();
        buttonFrame.setTitle("ButtonTest");
        buttonFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        buttonFrame.setVisible(true);
    }
}

class ButtonFrame extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    private JPanel buttonPanel;
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;

    public ButtonFrame() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        JButton yellowButton = new JButton("Yellow");
        ColorAction yellowAction = new ColorAction(Color.YELLOW);
        yellowButton.addActionListener(yellowAction);
        buttonPanel = new JPanel();
        buttonPanel.add(yellowButton);

        add(buttonPanel);
    }

    private class ColorAction implements ActionListener {

        private Color backgroundColor;

        public ColorAction(Color color) {
            backgroundColor = color;
        }
        
        @Override
        public void actionPerformed(ActionEvent e) {
            buttonPanel.setBackground(backgroundColor);
        }
    }
}