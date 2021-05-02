package com.principle.parser;

import java.util.ArrayList;

public class Process {
    BasicData basicData = new BasicData();
    String[] first = basicData.getFirst();
    String[] follow = basicData.getFollow();
    String[][] table = basicData.getTable();
    String testString = "";
    String gramString = "#E";
    char[] vn = basicData.getVn();
    char[] vt = basicData.getVt();
    int cycles = 1;
    int ptr = 0;

    public Process(String testString) {
        this.testString = testString;
    }

    private String[] processCells(int subPtr, int cycle) {
        String[] outPutString = {"", "", "", "", "", ""};
        outPutString[0] += Integer.toString(cycle);
        if (subPtr < testString.length()) {
            char tempChar = testString.charAt(subPtr);
            char stackTop = gramString.charAt(gramString.length() - 1);
            if (basicData.ifIsAVt(testString.charAt(subPtr)) == false) {
                outPutString[1] += "ERROR";
                outPutString[2] += "ERROR";
                outPutString[3] += "ERROR";
                outPutString[4] += "ERROR";
                outPutString[5] += "ERROR";
                return outPutString;
            }
            if (tempChar == '#' && stackTop == tempChar) {
                outPutString[1] += "OK";
                outPutString[2] += "OK";
                outPutString[3] += "OK";
                outPutString[4] += "OK";
                outPutString[5] += "OK";
            } else if (tempChar != '#' && stackTop == tempChar) {
                gramString = gramString.substring(0, gramString.length() - 1);
                outPutString[1] += gramString;
                outPutString[2] += testString.substring(subPtr + 1, testString.length());
                outPutString[3] += "";
                outPutString[4] += "GETNEXT(I)";
                outPutString[5] += "CONTINUE";
                ptr++;
            } else {
                if (basicData.ifIsAVn(stackTop)) {
                    int locVn = basicData.indexOfVn(stackTop);
                    int locVt = basicData.indexOfVt(tempChar);
                    if (table[locVn][locVt].length() != 0) {
                        String tempString = "";
                        gramString = gramString.substring(0, gramString.length() - 1);
                        for (int j = table[locVn][locVt].length() - 1; j > 2; j--) {
                            if (table[locVn][locVt].charAt(j) != 'ε') {
                                tempString += table[locVn][locVt].charAt(j);
                            }
                        }
                        gramString += tempString;
                        outPutString[1] += gramString;
                        outPutString[2] += testString.substring(subPtr, testString.length());
                        outPutString[3] += table[locVn][locVt];
                        outPutString[4] += "POP";
                        if (tempString.length() != 0) {
                            outPutString[4] += " PUSH(";
                            outPutString[4] += tempString;
                            outPutString[4] += ")";
                        }
                        outPutString[5] += "CONTINUE";
                    } else {
                        outPutString[1] += gramString;
                        outPutString[2] += testString.substring(subPtr, testString.length());
                        outPutString[3] += "ERROR";
                        outPutString[4] += "ERROR";
                        outPutString[5] += "ERRORINFINDTABLE";
                    }
                } else {
                    outPutString[1] += gramString;
                    outPutString[2] += testString.substring(subPtr, testString.length());
                    outPutString[3] += "ERROR";
                    outPutString[4] += "ERROR";
                    outPutString[5] += "CONTINUE";
                }
            }
        }
        return outPutString;
    }

    public ArrayList<String[]> process() {
        ArrayList<String[]> arrayList = new ArrayList<String[]>();
        String[] cells = {"", "", "", "", "", ""};
        cells[0] = Integer.toString(0);
        cells[1] = gramString;
        cells[2] = testString;
        cells[3] = "";
        cells[4] = "Initialized";
        cells[5] = "CONTINUE";
        arrayList.add(cells);
        while (!(cells[5].equals("OK"))) {
            if (cells[5].equals("ERROR")) {
                break;
            }
            cells = processCells(ptr, cycles);
            cycles++;
            arrayList.add(cells);
            if (cells[5].equals("ERRORINFINDTABLE")) {
                if (ptr < testString.length()) {
                    ptr++;
                } else {
                    break;
                }
            }
        };
        return arrayList;
    }
}
