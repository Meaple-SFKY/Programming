package com.principle.defined;

/**
 *  1   关键字
 *  2   标识符
 *  3   常数
 *  4   运算符
 *  5   关系运算符
 *  6   分界符
 * */

public class DefinitedCells {
    //关键字
    public String[] keyWords = new String[] {
        "auto"     ,"short"    ,"int"      ,"long"      ,
        "float"    ,"double"   ,"char"     ,"struct"    ,
        "union"    ,"enum"     ,"typedef"  ,"cosnt"     ,
        "unsigned" ,"signed"   ,"extern"   ,"register"  ,
        "static"   ,"volatle"  ,"void"     ,"if"        ,
        "else"     ,"switch"   ,"case"     ,"for"       ,
        "do"       ,"while"    ,"goto"     ,"continue"  ,
        "break"    ,"default"  ,"sizeof"   ,"return"
    };

    //分界符
    public char[] delimiters = {
        '.', ',', '(', ')', '[', ']', '{', '}', ':', '#', ';', '&', '"', '\\', '\''
    };

    //运算符
    public char[] arithmeticOperators = {
        '+', '-', '*', '/', '%', '|'
    };


    public String[] relationalOperators = {
        "<", "<=", "=", ">=", ">", "==", "<>"
    };
}
