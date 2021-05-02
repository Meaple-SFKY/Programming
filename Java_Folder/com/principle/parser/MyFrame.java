package com.principle.parser;

import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
 
public class MyFrame extends JFrame {
    private static final long serialVersionUID = 1L;

    JLabel label = new JLabel("Test String");
	JTextField textField = new JTextField(16);
	JButton button = new JButton("Confirm");
	
	public MyFrame(String title) {
        super(title);
		
		Container contentPane = getContentPane();
		contentPane.setLayout(new FlowLayout());
		
		contentPane.add(label);
		contentPane.add(textField);
		contentPane.add(button);
		
		button.addActionListener((e) -> {
			onButtonOk();
		});
	}
	
	private void onButtonOk() {
		String str = textField.getText();
		if(str.equals("")) {
			Object[] options = { "OK ", "CANCEL " }; 
			JOptionPane.showOptionDialog(null, "Nothing entered ", "Note", JOptionPane.DEFAULT_OPTION, 
			JOptionPane.WARNING_MESSAGE,null, options, options[0]);
		} else {
			FileForm fileForm = new FileForm(str);
			fileForm.formFile();
            JOptionPane.showMessageDialog(this,"You have entered: " + str + "\n" + 
                "Files are already int your desktop!");	
        }
	}
}