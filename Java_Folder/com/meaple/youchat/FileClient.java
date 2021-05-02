package com.meaple.youchat;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ClientFrame extends JFrame {
    /**
     *
     */
    private static final long serialVersionUID = 1L; //默认添加
    
    Socket client = null;
    private JTextField ipTextField;
    private JTextField portTextField;
    private JButton connect;
    private JButton send;
    private JButton clear;
    private JTextArea historyArea;
    private JTextField sendField;
    private CListener cListener;

    //初始化GUI界面
    private void init() {
        ipTextField = new JTextField("192.168.43.103");
        portTextField = new JTextField("19400");
        connect = new JButton("连接");
        send = new JButton("发送");
        clear = new JButton("清屏");
        historyArea = new JTextArea(30, 60);        //历史记录文本区
        sendField = new JTextField(40);             //码字文本区
        cListener = new CListener();

        setLocation(300, 100);
        setSize(400, 400);
        setBackground(Color.DARK_GRAY);
        historyArea.setBackground(Color.GRAY);
        setResizable(false);

        //窗口布局为BorderLatout
        Panel northPanel = new Panel();
        northPanel.add(new Label("IP"));
        northPanel.add(this.ipTextField);
        northPanel.add(new Label("Port"));
        northPanel.add(this.portTextField);
        northPanel.add(this.connect);
        this.add(northPanel, BorderLayout.NORTH);

        Panel centerPanel = new Panel();
        centerPanel.add(this.historyArea);
        this.add(centerPanel, BorderLayout.CENTER);

        Panel southPanel = new Panel();
        southPanel.add(this.sendField);
        southPanel.add(this.send);
        southPanel.add(this.clear);
        this.add(southPanel, BorderLayout.SOUTH);

        pack();
    }

    //构造函数
    public ClientFrame(String title) {
        super(title);
        init();

        //给“连接”、“发送”、“清屏”三个按钮添加事件监听
        connect.addActionListener(cListener);
        send.addActionListener(cListener);
        clear.addActionListener(cListener);

        //监听窗口，当点退出窗口按钮时，退出进程
        addWindowListener(
			new WindowAdapter()	{
	    		public void windowClosing(WindowEvent e) {
		    		try	{
		    			client.close();
		    		} catch(Exception ee) {
		    			ee.printStackTrace();
		    		}
		     		System.exit(0);
	    		}
	   		}
	   	);
    }

    class CListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            //获取事件按钮上的文本
            String actionString = e.getActionCommand();

            if (actionString.equals("连接")) {              //点按连接按钮
                try {
                    System.out.println("Hello");
                    connect.setEnabled(false);
                    int i = Integer.parseInt(portTextField.getText());  //获取端口号
                    client = new Socket(ipTextField.getText(), i);      //建立连接
                    historyArea.append("已连接\n");

                    //此线程的作用是当对方发信息过来时，把信息显示在文本区
                    ClientThread clientThread = new ClientThread();
                    clientThread.start();
                } catch(Exception ce) {
                    ce.printStackTrace();
                }
            } else if (actionString.equals("发送")) {       //点按发送按钮
                try {
                    String message = sendField.getText();
                    PrintWriter cc = new PrintWriter(client.getOutputStream());
                    if (message != "") {
                        cc.write(message + "\n");
                        cc.flush();                         //刷新缓冲区
                        historyArea.append("我: " + message + "\n");
                    }
                    sendField.setText("");
                } catch(Exception se) {
                    System.out.println("_________________\n____________________\n--------------");
                    se.printStackTrace();
                }
            } else if (actionString.equals("清屏")) {       //点按清屏按钮
                historyArea.setText("");
                historyArea.append("已连接\n");
                sendField.setText("");
            }
        }
    }

    class ClientThread extends Thread {
        public void run() {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
                String s = br.readLine();

                //等消息
                while (s != null) {
                    historyArea.append("小明: " + s + "\n");
                    s = br.readLine();
                }
            } catch(Exception re) {
                re.printStackTrace();
            }
        }
    }
}

public class FileClient {
    public static void main(String[] args) {
        ClientFrame clientFrame = new ClientFrame("小黄");
        clientFrame.setVisible(true);
    }
}