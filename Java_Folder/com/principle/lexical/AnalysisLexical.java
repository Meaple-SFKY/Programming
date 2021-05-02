package com.principle.lexical;

import java.io.*;
import com.principle.defined.*;

/**
 *  1   关键字
 *  2   标识符
 *  3   常数
 *  4   运算符
 *  5   关系运算符
 *  6   分界符
 * */

public class AnalysisLexical {
    public VectorArguments vectorArguments = new VectorArguments();
    public AnalysisLexical(String name) {
        fileName = name;
    }
    
    private int tempChar = 0;
    private String fileName;
    private StringBuffer tempStorString = new StringBuffer();
    private DefinitedCells definitedCells = new DefinitedCells();


    //判断是否是空格
    private boolean ifIsASpace(int slice) {
        int asciiCode = slice;
        if (asciiCode == 32) {
            return true;
        } else {
            return false;
        }
    }
    
    //判断是否是字母
    private boolean ifIsALetter(int slice) {
        int asciiCode = slice;
        if ((asciiCode >= 65 && asciiCode <= 90) ||
            (asciiCode >= 97 && asciiCode <= 122)) {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是数字
    private boolean ifIsADigital(int slice) {
        int asciiCode = slice;
        if (asciiCode >= 48 && asciiCode <= 57) {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是分界符
    private boolean ifIsADelimiter(int slice) {
        for (int i = 0; i < definitedCells.delimiters.length; i++) {
            if (definitedCells.delimiters[i] == (char)slice) {
                return true;
            }
        }
        return false;
    }

    //判断是否是关键字
    private boolean ifIsAKeyWord() {
        for (int i = 0; i < definitedCells.keyWords.length; i++) {
            if (tempStorString.toString().equals(definitedCells.keyWords[i])) {
                return true;
            }
        }
        return false;
    }

    //判断是否是标识符
    private boolean ifIsAIdentifier() {
        if (tempStorString.charAt(0) >= '0' && tempStorString.charAt(0) <= '9') {
            return false;
        } else {
            for (int i = 0; i < tempStorString.length(); i++) {
                int asciiCode = Integer.valueOf(tempStorString.charAt(i));
                if (((asciiCode >= 65 && asciiCode <= 90) ||
                    (asciiCode >= 97 && asciiCode <= 122) ||
                    (asciiCode == 95)) == false) {
                    return false;
                }
            }
            return true;
        }
    }

    //判断是否是常数
    private boolean ifIsASetDigitals() {
        int temp = 0;
        //末位是数字
        if ((tempStorString.charAt(tempStorString.length() - 1) >= '0' &&
            tempStorString.charAt(tempStorString.length() - 1) <= '9') ||
            tempStorString.charAt(tempStorString.length() - 1) == '.') {
            if (tempStorString.length() != 0) {
                for (int i = 0; i < tempStorString.length(); i++) {
                    if ((tempStorString.charAt(i) < '0' || tempStorString.charAt(i) > '9') && tempStorString.charAt(i) != '.') {
                        return false;
                    }
                    if (tempStorString.charAt(i) == '.') {
                        temp++;
                    }
                }
                if (temp > 1) {
                    return false;
                }
                return true;
            } else {
                return false;
            }
        } else if (tempStorString.charAt(tempStorString.length() - 1) == 'f' ||
                    tempStorString.charAt(tempStorString.length() - 1) == 'F' ||
                    tempStorString.charAt(tempStorString.length() - 1) == 'd' ||
                    tempStorString.charAt(tempStorString.length() - 1) == 'D') {
            //末位是f, F, d, D
            if (tempStorString.length() > 1) {
                for (int i = 0; i < tempStorString.length() - 1; i++) {
                    if ((tempStorString.charAt(i) < 48 || tempStorString.charAt(i) > 57) &&
                        tempStorString.charAt(i) != '.') {
                        return false;
                    }
                    if (tempStorString.charAt(i) == '.') {
                        temp++;
                    }
                }
                if (temp > 1) {
                    return false;
                }
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    //判断是否是单个关系运算符
    private boolean ifIsARelaOperator(int slice) {
        if ((char)slice == '=' || (char)slice == '<' || (char)slice == '>') {
            return true;
        } else {
            return false;
        }
    }

    //判断是否是算术运算符
    private boolean ifIsAArithmeticOperator(int slice) {
        for (int i = 0; i < definitedCells.arithmeticOperators.length; i++) {
            if ((char)slice == definitedCells.arithmeticOperators[i]) {
                return true;
            }
        }
        return false;
    }

    //判断是否是关系运算符
    private boolean ifIsRelaOperator() {
        for (int i = 0; i < definitedCells.relationalOperators.length; i++) {
            if (tempStorString.toString().equals(definitedCells.relationalOperators[i]) == true) {
                return true;
            }
        }
        return false;
    }

    //判断是否是运算符
    private boolean ifIsASetArithmeticOperators() {
        for (int i = 0; i < definitedCells.arithmeticOperators.length; i++) {
            for (int j = 0; j < tempStorString.length(); j++) {
                if (tempStorString.charAt(j) == definitedCells.arithmeticOperators[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    //连接经过处理的字符串和刚处理的字符
    private void addCharToString(int slice) {
        tempStorString.append((char)slice);
    }

    //输出关键字、标识符、常数、关系运算符、算术运算符有关信息
    private void printString(int line, int col) {
        if (tempStorString.length() != 0) {
            if (tempStorString.toString().equals(".") == true) {
                System.out.println(tempStorString + "\t\t(" + 1 + ", '" + tempStorString
                    + "')\t\t" + "分界符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
            } else if (tempStorString.length() > 8) {
                if (ifIsAKeyWord() == true) {
                    System.out.println(tempStorString + "\t(" + 1 + ", '" + tempStorString
                        + "')\t" + "关键字\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsASetDigitals() == true) {
                    vectorArguments.constantAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t(" + 3 + ", '" + tempStorString
                        + "')\t" + "常数\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsAIdentifier() == true) {
                    vectorArguments.identifierAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t(" + 2 + ", '" + tempStorString
                        + "')\t" + "标识符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsRelaOperator() == true) {
                    System.out.println(tempStorString + "\t(" + 5 + ", '" + tempStorString
                        + "')\t" + "关系运算符\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if(ifIsASetArithmeticOperators() == true) {
                    if (tempStorString.length() > 1) {
                        System.out.println(tempStorString + "\t\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    } else {
                        System.out.println(tempStorString + "\t\t(" + 4 + ", '" + tempStorString
                            + "')\t\t" + "运算符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    }
                } else {
                    System.out.println(tempStorString + "\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                }
            } else if (tempStorString.length() == 8) {
                if (ifIsAKeyWord() == true) {
                    System.out.println(tempStorString + "\t(" + 1 + ", '" + tempStorString
                        + "')\t" + "关键字\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsASetDigitals() == true) {
                    vectorArguments.constantAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t(" + 3 + ", '" + tempStorString
                        + "')\t" + "常数\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsAIdentifier() == true) {
                    vectorArguments.identifierAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t(" + 2 + ", '" + tempStorString
                        + "')\t\t" + "标识符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsRelaOperator() == true) {
                    System.out.println(tempStorString + "\t(" + 5 + ", '" + tempStorString
                        + "')\t" + "关系运算符\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if(ifIsASetArithmeticOperators() == true) {
                    if (tempStorString.length() > 1) {
                        System.out.println(tempStorString + "\t\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    } else {
                        System.out.println(tempStorString + "\t\t(" + 4 + ", '" + tempStorString
                            + "')\t\t" + "运算符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    }
                } else {
                    System.out.println(tempStorString + "\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                }
            } else {
                if (ifIsAKeyWord() == true) {
                    System.out.println(tempStorString + "\t\t(" + 1 + ", '" + tempStorString
                        + "')\t\t" + "关键字\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsASetDigitals() == true) {
                    vectorArguments.constantAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t\t(" + 3 + ", '" + tempStorString
                        + "')\t\t" + "常数\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsAIdentifier() == true) {
                    vectorArguments.identifierAdd(tempStorString.toString());
                    System.out.println(tempStorString + "\t\t(" + 2 + ", '" + tempStorString
                        + "')\t\t" + "标识符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if (ifIsRelaOperator() == true) {
                    System.out.println(tempStorString + "\t\t(" + 5 + ", '" + tempStorString
                        + "')\t\t" + "关系运算符\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                } else if(ifIsASetArithmeticOperators() == true) {
                    if (tempStorString.length() > 1) {
                        System.out.println(tempStorString + "\t\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    } else {
                        System.out.println(tempStorString + "\t\t(" + 4 + ", '" + tempStorString
                            + "')\t\t" + "运算符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                    }
                } else {
                    System.out.println(tempStorString + "\t\tERROR\t\t\tERROR\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
                }
            }
        }
    }

    //输出分界符有关信息
    private void printDelimiter(int slice, int line, int col) {
        System.out.println((char)slice + "\t\t(" + 6 + ", '" + (char)slice
            + "')\t\t" + "分界符\t\t" + "(" + (line + 1) + ", " + (col - tempStorString.length()) + ")");
    }

    //刷新临时字符串
    private void flushTempString() {
        tempStorString.delete(0, tempStorString.length());
    }

    public void analysis() {
        int lineLable = 0;
        int colLable = 0;
        BufferedReader bufferedReader;
        try {
            bufferedReader = new BufferedReader(new FileReader(fileName));
            while ((tempChar = bufferedReader.read()) != -1) {
                colLable++;
                if (ifIsASpace(tempChar) == false && (char)tempChar != '\n') {
                    if (ifIsALetter(tempChar) == true || ifIsADigital(tempChar) == true ||
                        (char)tempChar == '_') {
                        if (tempStorString.length() > 0 && ((ifIsASetArithmeticOperators() == true ||
                            ifIsARelaOperator(tempStorString.charAt(0)) == true))) {
                            printString(lineLable, colLable);
                            flushTempString();
                            addCharToString(tempChar);
                        } else {
                            if (tempStorString.length() > 0 && ifIsARelaOperator(tempStorString.charAt(0)) == true) {
                                printString(lineLable, colLable);
                                flushTempString();
                            }
                            addCharToString(tempChar);
                        }
                    } else if (ifIsADelimiter(tempChar)) {
                        if (ifIsASetArithmeticOperators() == true) {
                            printString(lineLable, colLable);
                            flushTempString();
                        }
                        if ((char)tempChar == '.') {
                            addCharToString(tempChar);
                        } else {
                            printString(lineLable, colLable);
                            flushTempString();
                            printDelimiter(tempChar, lineLable, colLable);
                        }
                    } else if (ifIsAArithmeticOperator(tempChar) == true) {
                        if (tempStorString.length() > 0) {
                            if (ifIsASetArithmeticOperators() == true) {
                                addCharToString(tempChar);
                            } else {
                                printString(lineLable, colLable);
                                flushTempString();
                                addCharToString(tempChar);
                            }
                        } else {
                            addCharToString(tempChar);
                        }
                    } else if (ifIsARelaOperator(tempChar) == true) {
                        if (tempStorString.length() > 0) {
                            if (ifIsARelaOperator(tempStorString.charAt(0)) == false) {
                                printString(lineLable, colLable);
                                flushTempString();
                                addCharToString(tempChar);
                            } else {
                                addCharToString(tempChar);
                                printString(lineLable, colLable);
                                flushTempString();
                            }
                        } else {
                            addCharToString(tempChar);
                        }
                    } else {
                        System.out.println((char)tempChar + "\t\tERROR\t\t\tERROR\t\t" + "(" + (lineLable + 1) + ", " + (colLable - tempStorString.length()) + ")");
                    }
                } else {
                    printString(lineLable, colLable);
                    flushTempString();
                }
                if ((char)tempChar == '\n') {
                    lineLable++;
                    colLable = 0;
                }
            }
        } catch (FileNotFoundException exceptionFile) {
            exceptionFile.printStackTrace();
        } catch (IOException exceptionIO) {
            exceptionIO.printStackTrace();
        }
    }
}