package com.meaple.guifaces;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

public class PlafFrame extends JFrame {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    private JPanel panel;

    public PlafFrame() {
        panel = new JPanel();

        UIManager.LookAndFeelInfo[] infos = UIManager.getInstalledLookAndFeels();
        for (UIManager.LookAndFeelInfo info : infos) {
            makeButton(info.getName(), info.getClassName());
            System.out.println(info.getName() + ", " + info.getClassName());
        }

        add(panel);
        pack();
    }

    private void makeButton(String name, String className) {
        JButton button = new JButton(name);
        panel.add(button);
        button.addActionListener(event -> {
            try {
                UIManager.setLookAndFeel(className);
                SwingUtilities.updateComponentTreeUI(this);
                pack();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public static void main(String[] args) {
        PlafFrame plafFrame = new PlafFrame();
        plafFrame.setTitle("PlafFrame");
        plafFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        plafFrame.setVisible(true);
    }
}