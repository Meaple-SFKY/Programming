package com.meaple.guifaces;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ActionFrame extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    
    private JPanel buttonPanel;
    private static final int DEFAULT_WIDTH = 300;
    private static final int DEFAULT_HEIGHT = 200;

    public ActionFrame() {
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        buttonPanel = new JPanel();

        Action yellowAction = new ColorAction("Yellow", Color.YELLOW);
        Action blueAction = new ColorAction("Blue", Color.BLUE);

        buttonPanel.add(new JButton(yellowAction));
        buttonPanel.add(new JButton(blueAction));

        add(buttonPanel);

        InputMap imap = buttonPanel.getInputMap(JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);
        imap.put(KeyStroke.getKeyStroke("ctrl Y"), "penel.yellow");
        imap.put(KeyStroke.getKeyStroke("ctrl B"), "panel.blue");

        ActionMap amap = buttonPanel.getActionMap();
        amap.put("panel.yellow", yellowAction);
        amap.put("panel.blue", blueAction);
    }

    public class ColorAction extends AbstractAction {

        /**
         *
         */
        private static final long serialVersionUID = 1L;

        public ColorAction(String name, Color c) {
            putValue(Action.NAME, name);
            putValue(Action.SHORT_DESCRIPTION, name.toLowerCase());
            putValue("Color", c);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            Color c = (Color)getValue("color");
            buttonPanel.setBackground(c);
        }   
    }

    public static void main(String[] args) {
        ActionFrame plafFrame = new ActionFrame();
        plafFrame.setTitle("ActionFrame");
        plafFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        plafFrame.setVisible(true);
    }
}
