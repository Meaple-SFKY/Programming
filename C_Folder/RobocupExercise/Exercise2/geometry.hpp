/*------------------------------- geometry.hpp ----------------------------------------*/
#ifndef _GEOMETRY_HPP_
#define _GEOMETRY_HPP_

#include<iostream>

using namespace std;

typedef struct point
{
    double x;
    double y;
} Point;

/*----------------------  定义Line类  -----------------------*/
class Line {
private:
    double a;
    double b;
    double c;

    void set_a(double a_temp) {
        a = a_temp;
    }

    void set_b(double b_temp) {
        b = b_temp;
    }

    void set_c(double c_temp) {
        c = c_temp;
    }

public:
    Line(double a_temp, double b_temp, double c_temp) {
        set_a(a_temp);
        set_b(b_temp);
        set_c(c_temp);
        type = "line";
    }
    ~Line() {};

    string type;

    double get_a(void) {
        return a;
    }

    double get_b(void) {
        return b;
    }

    double get_c(void) {
        return c;
    }
};

/*------------------------- 定义Circle类  --------------------*/
class Circle {
private:
    Point centerPoint;
    double radius;

    void setCenterPoint(double x, double y) {
        centerPoint.x = x;
        centerPoint.y = y;
    }

    void setRadius(double r) {
        radius = r;
    }

public:
    Circle(double x, double y, double r) {
        setCenterPoint(x, y);
        setRadius(r);
        type = "circle";
    }
    ~Circle() {};

    string type;

    Point getCenterPoint(void) {
        return centerPoint;
    }

    double getRadius(void) {
        return radius;
    }
};

/*------------------------------  定义Rectangle类  -------------------------------*/
class Rectangle {
private:
    Point leftTopPoint;
    Point leftBottomPoint;
    Point rightTopPoint;
    Point rightBottomPoint;

    void setLeftTopPoint(double x, double y) {
        leftTopPoint.x = x;
        leftTopPoint.y = y;
    }

    void setLeftBottomPoint(double x, double y) {
        leftBottomPoint.x = x;
        leftBottomPoint.y = y;
    }

    void setRightTopPoint(double x, double y) {
        rightTopPoint.x = x;
        rightTopPoint.y = y;
    }

    void setRightBottomPoint(double x, double y) {
        rightBottomPoint.x = x;
        rightBottomPoint.y = y;
    }

public:
    Rectangle(double leftTopX, double leftTopY, double leftBottomX, double leftBottomY, 
            double rightTopX, double rightTopY, double rightBottomX, double rightBottomY) {
        setLeftTopPoint(leftTopX, leftTopY);
        setLeftBottomPoint(leftBottomX, leftBottomY);
        setRightTopPoint(rightTopX, rightTopY);
        setRightBottomPoint(rightBottomX, rightBottomY);
        type = "rectangle";
    }
    ~Rectangle() {};

    string type;

    Point getLeftTopPoint(void) {
        return leftTopPoint;
    }

    Point getLeftBottomPoint(void) {
        return leftBottomPoint;
    }

    Point getRightTopPoint(void) {
        return rightTopPoint;
    }

    Point getRightBottomPoint(void) {
        return rightBottomPoint;
    }
};

#endif