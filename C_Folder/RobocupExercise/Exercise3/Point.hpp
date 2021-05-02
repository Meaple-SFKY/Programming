/*----------------------------------- Point.hpp ----------------------------------*/

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include<iostream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

//定义点结构
typedef struct {
    double X_index;
    double Y_index;
} Point;

//将整张图中已知点定义到一个结构中
typedef struct {
    Point P1;
    Point P2;
    Point P3;
    Point P4;
    Point P5;
    Point P6;
    Point P7;
    Point P8;
    Point P9;
    Point P10;
    Point C;
    Point G1;
    Point G2;
} GraphInfo;

//定义 Graph 
class Graph {
private:
    GraphInfo graphInfo;
    Point mySelf;
    void setMyself(double x, double y) {
        mySelf.X_index = x;
        mySelf.Y_index = y;
    }

public:
    Graph();
    ~Graph() {};

    //此函数计算机器人自己的位置信息
    void calculate(string message);

    //此函数返回机器人所在点的点结构
    Point getPoint();
};

//构造函数，设置图中已知点的坐标信息
Graph::Graph() {
    graphInfo.P1.X_index = -52.5;
    graphInfo.P1.Y_index = -32;
    graphInfo.P2.X_index = -52.5;
    graphInfo.P2.Y_index = -32;
    graphInfo.P3.X_index =  52.5;
    graphInfo.P3.Y_index =  32;
    graphInfo.P4.X_index =  52.5;
    graphInfo.P4.Y_index = -32;
    graphInfo.P5.X_index =  0;
    graphInfo.P5.Y_index = -32;
    graphInfo.P6.X_index =  0;
    graphInfo.P6.Y_index =  32;
    graphInfo.P7.X_index = -30;
    graphInfo.P7.Y_index = -7;
    graphInfo.P8.X_index = -30;
    graphInfo.P8.Y_index =  7;
    graphInfo.P9.X_index =  30;
    graphInfo.P9.Y_index =  7;
    graphInfo.P10.X_index = 30;
    graphInfo.P10.Y_index = -7;
    graphInfo.C.X_index =  0;
    graphInfo.C.Y_index =  0;
    graphInfo.G1.X_index = -52.5;
    graphInfo.G1.Y_index =  0;
    graphInfo.G2.X_index =  52.5;
    graphInfo.G2.Y_index =  0;
}

void Graph::calculate(string message) {
    Point point1, point2;
    char a[20];
    Point answerPoint1, answerPoint2;
    string name1 = "", name2 = "";
    string temp = "";
    double r1, r2, theta1, theta2;
    double circle_a, circle_b, circle_c, circle_d, circle_e, circle_f;
    double line_a, line_b, line_c;
    double aPart, bPart, cPart;
    double x1, x2, y1, y2;
    double yTemp;
    int i = 0, j = 0;

    //处理字符串信息，将有用的信息存储到变量中
    while (message.at(i) == ' ') {
        i++;
    }
    if (message.at(i) == '(') {
        i++;
    }
    j = i;
    while (message.at(i) != ' ') {
        i++;
    }
    name1 = message.substr(j, i - j);
    while (message.at(i) == ' ') {
        i++;
    }
    j = i;
    while (message.at(i) != ' ') {
        i++;
    }

    //以下四个变量用于字符串转化为数字
    stringstream sr1, sr2, st1, st2;

    sr1 << message.substr(j, i - j);
    sr1 >> r1;
    while (message.at(i) == ' ') {
        i++;
    }
    j = i;
    while (message.at(i) != ')') {
        i++;
    }
    st1 << message.substr(j, i - j);
    st1 >> theta1;
    while (message.at(i) != '(') {
        i++;
    }
    i++;
    j = i;
    while (message.at(i) != ' ') {
        i++;
    }
    name2 = message.substr(j, i - j);
    while (message.at(i) == ' ') {
        i++;
    }
    j = i;
    while (message.at(i) != ' '){
        i++;
    }
    sr2 << message.substr(j, i - j);
    sr2 >> r2;
    while (message.at(i) == ' ') {
        i++;
    }
    j = i;
    while (message.at(i) != ')') {
        i++;
    }
    st2 << message.substr(j, i - j);
    st2 >> theta2;

    //根据字符串“name1”、“name2”依次比较，以从graph.graphInfo中获取两点
    if (name1 == "P1") {
        point1 = graphInfo.P1;
    }
    else if (name1 == "P2") {
        point1 = graphInfo.P2;
    }
    else if (name1 == "P3") {
        point1 = graphInfo.P3;
    }
    else if (name1 == "P4") {
        point1 = graphInfo.P4;
    }
    else if (name1 == "P5") {
        point1 = graphInfo.P5;
    }
    else if (name1 == "P6") {
        point1 = graphInfo.P6;
    }
    else if (name1 == "P7") {
        point1 = graphInfo.P7;
    }
    else if (name1 == "P8") {
        point1 = graphInfo.P8;
    }
    else if (name1 == "P9") {
        point1 = graphInfo.P9;
    }
    else if (name1 == "P10") {
        point1 = graphInfo.P10;
    }
    else if (name1 == "C") {
        point1 = graphInfo.C;
    }
    else if (name1 == "G1") {
        point1 = graphInfo.G1;
    }
    else {
        point1 = graphInfo.G2;
    }

    if (name2 == "P1") {
        point2 = graphInfo.P1;
    }
    else if (name2 == "P2") {
        point2 = graphInfo.P2;
    }
    else if (name2 == "P3") {
        point2 = graphInfo.P3;
    }
    else if (name2 == "P4") {
        point2 = graphInfo.P4;
    }
    else if (name2 == "P5") {
        point2 = graphInfo.P5;
    }
    else if (name2 == "P6") {
        point2 = graphInfo.P6;
    }
    else if (name2 == "P7") {
        point2 = graphInfo.P7;
    }
    else if (name2 == "P8") {
        point2 = graphInfo.P8;
    }
    else if (name2 == "P9") {
        point2 = graphInfo.P9;
    }
    else if (name2 == "P10") {
        point2 = graphInfo.P10;
    }
    else if (name2 == "C") {
        point2 = graphInfo.C;
    }
    else if (name2 == "G1") {
        point2 = graphInfo.G1;
    }
    else {
        point2 = graphInfo.G2;
    }

    //计算
    circle_a = point1.X_index;
    circle_b = point1.Y_index;
    circle_c = r1;

    circle_d = point2.X_index;
    circle_e = point2.Y_index;
    circle_f = r2;

    line_a = 2 * (circle_a - circle_d);
    line_b = 2 * (circle_b - circle_e);
    line_c = -pow(circle_a, 2) - pow(circle_b, 2) + pow(circle_c, 2) + pow(circle_d, 2) + pow(circle_e, 2) - pow(circle_f, 2);

    aPart = pow(line_a, 2) + pow(line_b, 2);
    bPart = 2 * (line_a * line_b * circle_e - pow(line_b, 2) * circle_d - line_a * line_c);
    cPart = pow(line_b, 2) * (pow(circle_d, 2) + pow(circle_e, 2) - pow(circle_f, 2)) + pow(line_c, 2) - 2 * line_b * line_c * circle_e;

    x1 = (-bPart + pow(pow(bPart, 2) - 4 * aPart * cPart, 0.5)) / (2 * aPart);
    x2 = (-bPart - pow(pow(bPart, 2) - 4 * aPart * cPart, 0.5)) / (2 * aPart);
    y1 = (line_c - line_a * x1) / line_b;
    y2 = (line_c - line_a * x2) / line_b;

    if (x1 == x2 && y1 == y2) {
        setMyself(x1, y1);
    }
    else {
        if ((point1.X_index - point2.X_index) * (theta1 - theta2) > 0) {
            yTemp = ((point2.Y_index - point1.Y_index) * x1 + (point2.X_index - point1.X_index) * point1.Y_index - (point2.Y_index - point1.Y_index) * point1.X_index) / (point2.X_index - point1.X_index);
            if (y1 < yTemp) {
                setMyself(x1, y1);
            }
            else {
                setMyself(x2, y2);
            }
        }
        else if ((point1.X_index - point2.X_index) * (theta1 - theta2) < 0) {
            yTemp = ((point2.Y_index - point1.Y_index) * x1 + (point2.X_index - point1.X_index) * point1.Y_index - (point2.Y_index - point1.Y_index) * point1.X_index) / (point2.X_index - point1.X_index);
            if (y1 > yTemp) {
                setMyself(x1, y1);
            }
            else {
                setMyself(x2, y2);
            }
        }
        else {
            if ((point1.Y_index - point2.Y_index) * (theta1 - theta2) * (x1 - x2) > 0) {
                setMyself(x1, y1);
            }
            else {
                setMyself(x2, y2);
            }
        }
    }
}

Point Graph::getPoint() {
    return mySelf;
}

#endif