package lrparser;

import java.awt.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class DemoLr extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            TestField testField = new TestField();
            testField.setLocationByPlatform(true);
            testField.setTitle("Test String");
            testField.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            testField.setVisible(true);
        });
    }
}

class TestField extends JFrame {

    /**
     *
     */
    private static final long serialVersionUID = 1L;

    public TestField() {
        JTextField testString = new JTextField();

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(1, 2));
        panel.add(new JLabel("Test-String: ", SwingConstants.RIGHT));
        panel.add(testString);
        add(panel, BorderLayout.NORTH);

        JButton confirmButton = new JButton("Confirm");
        panel.add(confirmButton);
        confirmButton.addActionListener(event -> {
            String string = testString.getText().toString();
            ParTableFrame parTableFrame = new ParTableFrame(string);
            parTableFrame.setLocationByPlatform(true);
            parTableFrame.setTitle("Parser");
            parTableFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            parTableFrame.setVisible(true);
        });
        pack();
    }
}

class ParTableFrame extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    private String[] parserTitles;
    private String[][] parserTable;

    public ParTableFrame(String str) {
        parserTable = new Process(str).parserTable();
        parserTitles = new FirstSet().title;

        DefaultTableModel parModel = new DefaultTableModel(parserTable, parserTitles);
        JTable parTable = new JTable(parModel);
        add(new JScrollPane(parTable), BorderLayout.CENTER);

        pack();
    }
}
