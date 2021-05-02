package com.meaple.guifaces;

import java.awt.*;
import javax.swing.*;

public class TextComponentFrame extends JFrame {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public static final int TEXTAREA_RWAS = 8;
    public static final int TEXTAREA_COLUMNS = 20;

    public TextComponentFrame() {
        JTextField textField = new JTextField();
        JPasswordField passwordField = new JPasswordField();

        JPanel northPanel = new JPanel();
        northPanel.setLayout(new GridLayout(2, 2));
        northPanel.add(new JLabel("User name: ", SwingConstants.RIGHT));
        northPanel.add(textField);
        northPanel.add(new JLabel("Password: ", SwingConstants.RIGHT));
        northPanel.add(passwordField);

        add(northPanel, BorderLayout.NORTH);

        JTextArea textArea = new JTextArea(TEXTAREA_RWAS, TEXTAREA_COLUMNS);
        JScrollPane scrollPane = new JScrollPane(textArea);
        add(scrollPane, BorderLayout.CENTER);

        JPanel southPanel = new JPanel();

        JButton insertButton = new JButton("Insert");
        southPanel.add(insertButton);
        insertButton.addActionListener(event -> {
            textArea.append("User name: " + textField.getText() + "\nPassword: " +
            new String(passwordField.getPassword()) + "\n");
        });
        add(southPanel, BorderLayout.SOUTH);
        pack();
    }

    public static void main(String[] args) {
        TextComponentFrame textComponentFrame = new TextComponentFrame();
        textComponentFrame.setTitle("TextComponentFrame");
        textComponentFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        textComponentFrame.setVisible(true);
    }
}
