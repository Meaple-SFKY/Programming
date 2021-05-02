/*------------------------------------------- demo.cpp ----------------------------------------------*/
#include<cmath>
#include"geometry.hpp"

Point judgeInter(Line, Point, Point);
bool judgeCoincide(Line, Rectangle);

int main(void) {
    double aFixed, bFixed, cFixed;
    double aTemp, bTemp, cTemp;
    double circleX, circleY, radius;
    double point_ltX, point_ltY, point_lbX, point_lbY, point_rtX, point_rtY, point_rbX, point_rbY;

    cout << "Please input the parameter of your Fixed straight line: ";
    cin >> aFixed >> bFixed >> cFixed;

    cout << "Please input the parameter of your Requested straight line: ";
    cin >> aTemp >> bTemp >> cTemp;

    cout << "Please input the parameter of your circle: ";
    cin >> circleX >> circleY >> radius;

    cout << "Please input the parameter of your rectangle: ";
    cin >> point_ltX >> point_ltY >> point_lbX >> point_lbY 
            >> point_rtX >> point_rtY >> point_rbX >> point_rbY;

    Line fixedLine(aFixed, bFixed, cFixed);
    Line tempLine(aTemp, bTemp, cTemp);
    Circle circle(circleX, circleY, radius);
    Rectangle rectangle(point_ltX, point_ltY, point_lbX, point_lbY, point_rtX, point_rtY, point_rbX, point_rbY);

    //计算两直线的交点
    if (fixedLine.get_a() / fixedLine.get_b() != tempLine.get_a() / tempLine.get_b()) {
        Point llInter;
        double x, y;
        x = (fixedLine.get_b() * tempLine.get_c() - fixedLine.get_c() * tempLine.get_b()) / 
                (fixedLine.get_a() * tempLine.get_b() - fixedLine.get_b() * tempLine.get_a());
        y = (fixedLine.get_a() * tempLine.get_c() - fixedLine.get_c() * tempLine.get_a()) / 
                (fixedLine.get_b() * tempLine.get_a() - fixedLine.get_a() * tempLine.get_b());
        llInter.x = x;
        llInter.y = y;
        cout << "The coordinates of the intersection of the two lines is: (" 
                << llInter.x << ", " << llInter.y << ")" << endl;
    }
    else {
        cout << "The two straight lines have no intersection or they coincide" << endl;
    }

    //计算直线与圆的交点
    double distance = fabs(fixedLine.get_a() * circle.getCenterPoint().x + fixedLine.get_b() * circle.getCenterPoint().y 
            + circle.getRadius()) / pow((pow(fixedLine.get_a(), 2) + pow(fixedLine.get_b(), 2)), 0.5);
    if (distance < circle.getRadius()) {
        double xFir, yFir, xSec, ySec;
        double aPart, bPart, cPart;
        aPart = pow(fixedLine.get_a(), 2) + pow(fixedLine.get_b(), 2);
        bPart = 2 * fixedLine.get_a() * fixedLine.get_c() - 2 * pow(fixedLine.get_b(), 2) * circle.getCenterPoint().x
                + 2 * fixedLine.get_a() * fixedLine.get_b() * circle.getCenterPoint().y;
        cPart = pow(fixedLine.get_b(), 2) * (pow(circle.getCenterPoint().x, 2) + pow(circle.getCenterPoint().y, 2) 
                - pow(circle.getRadius(), 2)) - pow(fixedLine.get_c(), 2) + 2 * fixedLine.get_b() * circle.getCenterPoint().y * fixedLine.get_c();
        xFir = (-bPart + pow(pow(bPart, 2) - 4 * aPart * cPart, 0.5)) / (2 * aPart);
        xSec = (-bPart - pow(pow(bPart, 2) - 4 * aPart * cPart, 0.5)) / (2 * aPart);
        yFir = -(fixedLine.get_c() + fixedLine.get_a() * xFir) / fixedLine.get_b();
        ySec = -(fixedLine.get_c() + fixedLine.get_a() * xSec) / fixedLine.get_b();
        cout << "The coordinates of the two intersection points of the line and the circle are: (" << xFir << ", " << yFir
                << "), (" << xSec << ", " << ySec << ")." << endl;
    }
    else if (distance == circle.getRadius()) {
        double x, y;
        double aPart, bPart, cPart;
        aPart = pow(fixedLine.get_a(), 2) + pow(fixedLine.get_b(), 2);
        bPart = 2 * fixedLine.get_a() * fixedLine.get_c() - 2 * pow(fixedLine.get_b(), 2) * circle.getCenterPoint().x
                + 2 * fixedLine.get_a() * fixedLine.get_b() * circle.getCenterPoint().y;
        cPart = pow(fixedLine.get_b(), 2) * (pow(circle.getCenterPoint().x, 2) + pow(circle.getCenterPoint().y, 2) 
                - pow(circle.getRadius(), 2)) + pow(fixedLine.get_c(), 2) - 2 * circle.getCenterPoint().y * fixedLine.get_c();
        x = -bPart / (2 * aPart);
        y = -(cPart + aPart * x) / bPart;
        cout << "The coordinates of the  intersection point of the line and the circle are: (" << x << ", " << y
                << ")." << endl;
    }
    else {
        cout << "Line and circle have no intersection";
    }

    //计算直线与矩形的交点
    if (judgeCoincide(fixedLine, rectangle) == true) {
        cout << "Straight line coincides with one side of the rectangle." << endl;
    }
    else {
        bool t = false, l = false, b = false, r = false;
        Point lPoint, tPoint, bPoint, rPoint;
        lPoint = judgeInter(fixedLine, rectangle.getLeftTopPoint(), rectangle.getLeftBottomPoint());
        tPoint = judgeInter(fixedLine, rectangle.getLeftTopPoint(), rectangle.getRightTopPoint());
        bPoint = judgeInter(fixedLine, rectangle.getLeftBottomPoint(), rectangle.getRightBottomPoint());
        rPoint = judgeInter(fixedLine, rectangle.getRightTopPoint(), rectangle.getRightBottomPoint());
        if ((lPoint.x >= rectangle.getLeftBottomPoint().x && lPoint.x <= rectangle.getLeftTopPoint().x)
                || (lPoint.x <= rectangle.getLeftBottomPoint().x && lPoint.x >= rectangle.getLeftTopPoint().x)) {
            l = true;
        }
        if ((tPoint.x >= rectangle.getLeftTopPoint().x && tPoint.x <= rectangle.getRightTopPoint().x)
                || (tPoint.x <= rectangle.getLeftTopPoint().x && lPoint.x >= rectangle.getRightTopPoint().x)) {
            t = true;
        }
        if ((bPoint.x >= rectangle.getLeftBottomPoint().x && bPoint.x <= rectangle.getRightBottomPoint().x)
                || (bPoint.x <= rectangle.getLeftBottomPoint().x && bPoint.x >= rectangle.getRightBottomPoint().x)) {
            b = true;
        }
        if ((rPoint.x >= rectangle.getRightTopPoint().x && rPoint.x <= rectangle.getRightBottomPoint().x)
                || (rPoint.x <= rectangle.getRightTopPoint().x && rPoint.x >= rectangle.getRightBottomPoint().x)) {
            r = true;
        }
        cout << "The coordinates of the intersection of a line and a rectangle: ";
        if (l == true && t == true) {
            if ((lPoint.x == tPoint.x) && (lPoint.y == tPoint.y)) {
                t = false;
            }
        }
        if (l == true && b == true) {
            if ((lPoint.x == bPoint.x) && (lPoint.y == bPoint.y)) {
                b = false;
            }
        }
        if (r == true && t == true) {
            if ((rPoint.x == tPoint.x) && (rPoint.y == tPoint.y)) {
                t = false;
            }
        }
        if (r == true && b == true) {
            if ((rPoint.x == bPoint.x) && (rPoint.y == bPoint.y)) {
                b = false;
            }
        }
        if (l == true) {
            cout << "(" << lPoint.x << ", " << lPoint.y << ") ";
        }
        if (t == true) {
            cout << "(" << tPoint.x << ", " << tPoint.y << ") ";
        }
        if (b == true) {
            cout << "(" << bPoint.x << ", " << bPoint.y << ") ";
        }
        if (r == true) {
            cout << "(" << rPoint.x << ", " << rPoint.y << ") ";
        }
        cout << "." << endl;
        return 0;
    }
}

//判断直线是否与矩形的一边重合
bool judgeCoincide(Line line, Rectangle rectangle) {
    if ((line.get_a() * rectangle.getLeftTopPoint().x + line.get_b() * rectangle.getLeftTopPoint().y + line.get_c() == 0)
            && (line.get_a() * rectangle.getLeftBottomPoint().x + line.get_b() * rectangle.getLeftBottomPoint().y + line.get_c() == 0)) {
        return true;
    }
    if ((line.get_a() * rectangle.getLeftTopPoint().x + line.get_b() * rectangle.getLeftTopPoint().y + line.get_c() == 0)
            && (line.get_a() * rectangle.getRightTopPoint().x + line.get_b() * rectangle.getRightTopPoint().y + line.get_c() == 0)) {
        return true;
    }
    if ((line.get_a() * rectangle.getRightBottomPoint().x + line.get_b() * rectangle.getRightBottomPoint().y + line.get_c() == 0)
            && (line.get_a() * rectangle.getLeftBottomPoint().x + line.get_b() * rectangle.getLeftBottomPoint().y + line.get_c() == 0)) {
        return true;
    }
    if ((line.get_a() * rectangle.getRightTopPoint().x + line.get_b() * rectangle.getRightTopPoint().y + line.get_c() == 0)
            && (line.get_a() * rectangle.getRightBottomPoint().x + line.get_b() * rectangle.getRightBottomPoint().y + line.get_c() == 0)) {
        return true;
    }
    else {
        return false;
    }
}

//获取确定直线与确定两点构成的直线的交点
Point judgeInter(Line line, Point pointFir, Point pointSec) {
    double a = line.get_a();
    double b = line.get_b();
    double c = line.get_c();
    double d = pointSec.y - pointFir.y;
    double e = pointFir.x - pointSec.x;
    double f = (pointSec.x - pointFir.x) * pointFir.y - (pointSec.y - pointFir.y) * pointFir.x;
    double x = (b * f - c * e) / (a * e - b * d);
    double y = (a * f - c * d) / (b * d - a * e);
    Point point;
    point.x = x;
    point.y = y;

    return point;
}