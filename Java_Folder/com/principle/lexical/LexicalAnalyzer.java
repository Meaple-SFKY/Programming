package com.principle.lexical;

/**
 *  1   关键字
 *  2   标识符
 *  3   常数
 *  4   运算符
 *  5   关系运算符
 *  6   分界符
 * */

public class LexicalAnalyzer {
    public static void main(String[] args) {
        // String fileName = "/Users/sfky/Documents/Programming/Java_Folder/com/principle/examplefir.c";
        // String fileName = "/Users/sfky/Documents/Programming/Java_Folder/com/principle/examplesec.c";
        String fileName = "/Users/sfky/Documents/Programming/Java_Folder/com/principle/examplethi.c";
        AnalysisLexical analysisLexical = new AnalysisLexical(fileName);
        analysisLexical.analysis();
    }
}
