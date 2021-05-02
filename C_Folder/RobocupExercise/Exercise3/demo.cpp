/*----------------------------------- demo.cpp ---------------------------------*/

#include"Point.hpp"

int main(void) {
    Graph graph;
    Point point;
    string message;
    cout << "Please enter the information: ";
    getline(cin, message);
    graph.calculate(message);
    point = graph.getPoint();
    cout << "The absolute position of the robot is (" << point.X_index << ", " << point.Y_index << ")" << endl;
    return 0;
}