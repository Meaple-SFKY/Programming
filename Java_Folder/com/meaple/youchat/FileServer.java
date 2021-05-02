package com.meaple.youchat;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

class ServerFrame extends Frame {
    /**
     *
     */
    private static final long serialVersionUID = 1L;
    
    ServerSocket server = null;
    Socket client = null;

    private String port;
    private JTextField portTextField;
    private JButton start;
    private JButton send;
    private JButton clear;
    private JTextArea historyArea;
    private JTextField sendField;
    private SListener sListener = new SListener();

    void init() {
        port = "2001";
        portTextField = new JTextField(port);
        start = new JButton("启动");
        send = new JButton("发送");
        clear = new JButton("清屏");
        historyArea = new JTextArea(30, 60);
        sendField = new JTextField(40);
        sListener = new SListener();

        setLocation(1200, 100);
        setSize(400, 400);
        setBackground(Color.GRAY);
        historyArea.setBackground(Color.LIGHT_GRAY);
        setResizable(false);

        Panel northPanel = new Panel();
        northPanel.add(new Label("Port"));
        northPanel.add(this.portTextField);
        northPanel.add(this.start);
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

    public ServerFrame(String title) {
        super(title);
        init();

        start.addActionListener(sListener);
        send.addActionListener(sListener);
        clear.addActionListener(sListener);

        addWindowListener(
			new WindowAdapter()	{
	    		public void windowClosing(WindowEvent e) {
                    try	{
                        server.close();
                    } catch(Exception ee) {
                        ee.printStackTrace();
                    }
                    System.exit(0);
	    		}
	   		}
	   	);
    }

    class SListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String actionString = e.getActionCommand();
            if (actionString.equals("启动")) {
                try {
                    start.setEnabled(false);
                    int i = Integer.parseInt(portTextField.getText());
                    historyArea.append("已连接\n");
                    server = new ServerSocket(i);
                    client = server.accept();

                    ServerThread serverThread = new ServerThread();
                    serverThread.start();
                } catch(Exception ce) {
                    ce.printStackTrace();
                }
            } else if (actionString.equals("发送")) {
                try {
                    String str = sendField.getText();
                    PrintWriter ss = new PrintWriter(client.getOutputStream());
                    if (str != "") {
                        ss.write(str + "\n");
                        ss.flush();
                        historyArea.append("我: " + str + "\n");
                    }
                    sendField.setText("");
                } catch(Exception se) {
                    se.printStackTrace();
                }
            } else if (actionString.equals("清屏")) {
                historyArea.setText("");
                historyArea.append("已连接\n");
                sendField.setText("");
            }
        }
    }

    class ServerThread extends Thread {
        public void run() {
            try {
                BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
                String s = br.readLine();
                while (s != null) {
                    historyArea.append("小黄: " + s + "\n");
                    s = br.readLine();
                }
            } catch(Exception re) {
                re.printStackTrace();
            }
        }
    }
}

public class FileServer {
    public static void main(String[] args) {
        ServerFrame serverFrame = new ServerFrame("小明");
        serverFrame.setVisible(true);
    }
}



/**
 * 运行后Terminal报错，检查发现没有给客户端（小黄）指定端口号
 * 建立连接后无法发消息，且程序卡死，解决方式是给等待对方消息的部分建个线程
 * 窗口无法正常关闭，使用windowClosing侦听窗口，就可以正常关闭
*/