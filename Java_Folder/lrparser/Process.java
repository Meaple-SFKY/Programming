package lrparser;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Line {
    int label;
    ArrayList<Integer> statusStack;
    String symbolStack;
    String bufferStack;
    String action;

    public Line() {
        label = 0;
        statusStack = new ArrayList<Integer>();
        symbolStack = "";
        bufferStack = "";
        action = "";
    }

    public String labelToStr() {
        return Integer.toString(label);
    }

    public String statusToStr() {
        String string = "";
        string += Integer.toString(statusStack.get(0));
        for (int i = 1; i < statusStack.size(); i++) {
            string += " ";
            string += Integer.toString(statusStack.get(i));
        }
        return string;
    }

    public int getStatusTop() {
        return statusStack.get(statusStack.size() - 1);
    }

    public void popStatusStack() {
        statusStack.remove(statusStack.size() - 1);
    }

    public void pushStatusStack(int status) {
        statusStack.add(status);
    }

    public void popSymbolStack() {
        symbolStack = symbolStack.substring(0, symbolStack.length() - 1);
    }

    public void pushSymbolStack(String symbol) {
        symbolStack += symbol;
    }

    public char getBufferTop() {
        return bufferStack.charAt(0);
    }

    public void freshBuffer() {
        bufferStack = bufferStack.substring(1, bufferStack.length());
    }

    public void freshAction(String actionString) {
        action = actionString;
    }
}

public class Process {
    SetTable setTable = new SetTable();
    FirstSet firstSet = new FirstSet();
    ArrayList<String> actionList = new ArrayList<String>();
    ArrayList<Line> lineList = new ArrayList<Line>();
    String[][] analysisTable = setTable.getAnalysisTable();
    ItemFamily itemFamily = setTable.getFamily();
    Line line = new Line();
    String testString = "";
    int actionIndex = setTable.actionIndex();
    int goToIndex = setTable.gotoIndex();
    int currentLable = 1;

    private int indexOfVt(char ch) {
        return setTable.indexOfVt(ch);
    }

    private int indexOfVn(char ch) {
        return setTable.indexOfVn(ch);
    }

    public Process(String str) {
        /* itemFamily.printFamily();
        System.out.println("------------------------------------------------------------------"); */
        this.testString = str;
        initLine();
        process();
        tidyList();
    }

    private void initLine() {
        line.label = currentLable;
        line.pushStatusStack(0);
        line.pushSymbolStack(Character.toString(firstSet.getVt()[firstSet.getVt().length - 1]));
        line.bufferStack = testString;
        String nowAction = analysisTable[line.getStatusTop()][indexOfVt(line.getBufferTop()) + actionIndex];
        int temp = Integer.valueOf(nowAction.substring(1, nowAction.length()));
        line.freshAction("ACTION[" + line.getStatusTop() + "," + line.getBufferTop() + "] = " + nowAction + ", Status " + temp + " Move Into Stack");
        Line newLine = new Line();
        ArrayList<Integer> newArray = new ArrayList<Integer>(Arrays.asList(new Integer[line.statusStack.size()]));
        newLine.action = line.action;
        newLine.bufferStack = line.bufferStack;
        newLine.label = line.label;
        Collections.copy(newArray, line.statusStack);
        newLine.statusStack = newArray;
        newLine.symbolStack = line.symbolStack;
        lineList.add(newLine);
    }

    public void process() {
        while (true) {
            line.label++;
            if (line.bufferStack.length() != 0) {
                if (indexOfVt(line.getBufferTop()) == -1) {
                    break;
                } else {
                    String nowAction = analysisTable[line.getStatusTop()][indexOfVt(line.getBufferTop()) + actionIndex];
                    if (nowAction.length() != 0) {
                        if (nowAction.charAt(0) == 's') {
                            int temp = Integer.valueOf(nowAction.substring(1, nowAction.length()));
                            line.freshAction("ACTION[" + line.getStatusTop() + "," + line.getBufferTop() + "] = " + nowAction + ", Status " + temp + " Move Into Stack");
                            line.pushStatusStack(temp);
                            line.pushSymbolStack(Character.toString(line.getBufferTop()));
                            line.freshBuffer();
                            actionList.add(line.action);
                            Line newLine = new Line();
                            ArrayList<Integer> newArray = new ArrayList<Integer>(Arrays.asList(new Integer[line.statusStack.size()]));
                            newLine.action = line.action;
                            newLine.bufferStack = line.bufferStack;
                            newLine.label = line.label;
                            Collections.copy(newArray, line.statusStack);
                            newLine.statusStack = newArray;
                            newLine.symbolStack = line.symbolStack;
                            lineList.add(newLine);
                        } else if (nowAction.charAt(0) == 'r') {
                            int temp = Integer.valueOf(nowAction.substring(1, nowAction.length()));
                            String tempStr = new FirstSet().extendGrammar[temp];
                            int len = tempStr.length() - 3;
                            for (int i = 0; i < len; i++) {
                                line.popStatusStack();
                                line.popSymbolStack();
                            }
                            int inPush = Integer.valueOf(analysisTable[line.getStatusTop()][indexOfVn(tempStr.charAt(0)) + goToIndex]);
                            line.freshAction(nowAction + ", " + tempStr + " Reduce, GOTO(" + line.getStatusTop() + "," + tempStr.charAt(0) + ") = " + inPush + " Move Into Stack");
                            line.pushStatusStack(inPush);
                            line.pushSymbolStack(Character.toString(tempStr.charAt(0)));
                            actionList.add(line.action);
                            Line newLine = new Line();
                            ArrayList<Integer> newArray = new ArrayList<Integer>(Arrays.asList(new Integer[line.statusStack.size()]));
                            newLine.action = line.action;
                            newLine.bufferStack = line.bufferStack;
                            newLine.label = line.label;
                            Collections.copy(newArray, line.statusStack);
                            newLine.statusStack = newArray;
                            newLine.symbolStack = line.symbolStack;
                            lineList.add(newLine);
                        } else if (nowAction.equals("acc")) {
                            break;
                        } else {
                            line.freshAction("ERROR; Location 1");
                            break;
                        }
                    } else {
                        line.freshAction("ERROR; Location 2");
                        break;
                    }
                }
            } else {
                break;
            }
        }
    }

    public void tidyList() {
        for (int i = 0; i < actionList.size(); i++) {
            lineList.get(i).freshAction(actionList.get(i));
        }
        String str = Character.toString(firstSet.getVt()[firstSet.getVt().length - 1]);
        String string = str + Character.toString(firstSet.grammar[0].charAt(0));
        if (lineList.get(lineList.size() - 1).bufferStack.equals(str) && lineList.get(lineList.size() - 1).symbolStack.equals(string)) {
            lineList.get(lineList.size() - 1).freshAction("Acc: Successfully completed the analysis process");
        } else {
            lineList.get(lineList.size() - 1).freshAction("Failed to completed the analysis process");
        }
    }

    public String[][] listToStrTable() {
        String[][] table = new String[lineList.size()][5];
        for (int i = 0; i < lineList.size(); i++) {
            table[i][0] = lineList.get(i).labelToStr();
            table[i][1] = lineList.get(i).statusToStr();
            table[i][2] = lineList.get(i).symbolStack;
            table[i][3] = lineList.get(i).bufferStack;
            table[i][4] = lineList.get(i).action;
        }
        return table;
    }

    public String[][] parserTable() {
        String[][] table = null;
        int line = analysisTable.length;
        if (line > 0) {
            int col = analysisTable[0].length;
            table = new String[line][col + 1];
            for (int i = 0; i < table.length; i++) {
                table[i][0] = Integer.toString(i);
                for (int j = 1; j < table[i].length; j++) {
                    table[i][j] = analysisTable[i][j - 1];
                }
            }
            return table;
        } else {
            return table;
        }
    }
}
