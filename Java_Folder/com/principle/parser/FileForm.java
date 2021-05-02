package com.principle.parser;

import java.io.*;
import java.util.ArrayList;

public class FileForm {
    public String testString = "";
    public FileForm(String testString) {
        this.testString = testString;
    }
    ArrayList<String[]> processList = new ArrayList<String[]>();
    public void formFile () {
        Process process = new Process(testString);
        processList = process.process();
        String[] first = process.first;
        String[] follow = process.follow;
        String[][] table = process.table;
        File processFile = new File("/Users/sfky/Desktop/Process.csv");
        File firstFollowFile = new File("/Users/sfky/Desktop/First_Follow.csv");
        File tableFile = new File("/Users/sfky/Desktop/Table.csv");
        try{
            OutputStreamWriter processStream = new OutputStreamWriter(new FileOutputStream(processFile));
            OutputStreamWriter firFolStream = new OutputStreamWriter(new FileOutputStream(firstFollowFile));
            OutputStreamWriter tableStream = new OutputStreamWriter(new FileOutputStream(tableFile));
            BufferedWriter processText = new BufferedWriter(processStream);
            BufferedWriter firFolText = new BufferedWriter(firFolStream);
            BufferedWriter tableText = new BufferedWriter(tableStream);
            processText.write("Step,Symbol Stack,Input String,Production Used,Action");
            for(int i = 0; i < processList.size(); i++){
                processText.newLine();
                processText.write(processList.get(i)[0] + "," + processList.get(i)[1] + ","
                    + processList.get(i)[2] + "," + processList.get(i)[3] + "," + processList.get(i)[4]);
            }
            processText.flush();
            processText.close();

            firFolText.write("Non-terminal,First Set,Follow Set");
            for (int i = 0; i < process.vn.length; i++) {
                firFolText.newLine();
                firFolText.write(process.vn[i] + ", " + first[i].toString() + ", " + follow[i]);
            }
            firFolText.newLine();
            firFolText.flush();
            firFolText.close();

            tableText.write("Symbols");
            for (int i = 0; i < process.vt.length; i++) {
                tableText.write("," + process.vt[i]);
            }
            for (int i = 0; i < process.vn.length; i++) {
                tableText.newLine();
                tableText.write(process.vn[i]);
                for (int j = 0; j < process.vt.length; j++) {
                    tableText.write("," + table[i][j]);
                }
            }
            tableText.flush();
            tableText.close();
        } catch (FileNotFoundException exceptionFile) {
            exceptionFile.printStackTrace();
        } catch (IOException exceptionIO) {
            exceptionIO.printStackTrace();
        }
    }
}
