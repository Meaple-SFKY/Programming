/*------------------------------  main.cpp  ------------------------------*/
#include "maze.hpp"

int main(void) {
    srand((unsigned int)time(NULL));
    int key;
    Point entrance, destination;

    menu_Fir();
    cin >> key;
    while (key != 3) {
        if (key == 1) {
            int size;
            int subkey;
            cout << "Pease enter the size: ";
            cin >> size;
            cout << "Please enter the X-axis and the Y-axis of your entrance: ";
            cin >> entrance.X_Locat >> entrance.Y_Locat;
            cout << "Please enter the X-axis and the Y-axis of your destination: ";
            cin >> destination.X_Locat >> destination.Y_Locat;
            Maze maze(size);
            maze.setStartPoint(entrance);
            maze.setEndPoint(destination);
            maze.setGraphFromArray();
            menu_Sec();
            cin >> subkey;
            while (subkey != 4) {
                if (subkey == 1) {
                    Point newPoint;
                    int type;
                    cout << "Please set its type(wall-1, space-0, exit-2): ";
                    cin >> type;
                    while (type != 2) {
                        cout << "Please enter the Abscissa and the Ordinate: ";
                        cin >> newPoint.X_Locat >> newPoint.Y_Locat;
                        if (type == 1) {
                            maze.editWallPoint(newPoint);
                        }
                        else {
                            maze.editRoadPoint(newPoint);
                        }
                        cout << "Please set its type(wall-1, space-0, exit-2): ";
                        cin >> type;
                    }
                    maze.setGraphFromArray();
                }
                else if (subkey == 2) {
                    maze.printMaze(maze.MAZE);
                }
                else {
                    maze.getPath();
                    maze.printMaze(maze.MAZE);
                }
                menu_Sec();
                cin >> subkey;
            }
        }
        else {
            int subkey;
            string fileName;
            cout << "Pease enter the fileName: ";
            cin >> fileName;
            cout << "Please enter the X-axis and the Y-axis of your entrance: ";
            cin >> entrance.X_Locat >> entrance.Y_Locat;
            cout << "Please enter the X-axis and the Y-axis of your destination: ";
            cin >> destination.X_Locat >> destination.Y_Locat;
            Maze maze(fileName);
            maze.setStartPoint(entrance);
            maze.setEndPoint(destination);
            maze.setGraphFromArray();
            menu_Sec();
            cin >> subkey;
            while (subkey != 4) {
                if (subkey == 1) {
                    Point newPoint;
                    int type;
                    cout << "Please enter the Abscissa and the Ordinate: ";
                    cin >> newPoint.X_Locat >> newPoint.Y_Locat;
                    cout << "Please set its type(wall-1, space-0, exit-2): ";
                    cin >> type;
                    while (type != 2) {
                        if (type == 1) {
                            maze.editWallPoint(newPoint);
                        }
                        else {
                            maze.editRoadPoint(newPoint);
                        }
                        cin >> type;
                    }
                    maze.MAZE.array[newPoint.X_Locat][newPoint.Y_Locat] = type;
                    maze.setGraphFromArray();
                }
                else if (subkey == 2) {
                    maze.printMaze(maze.MAZE);
                }
                else {
                    maze.getPath();
                    maze.printMaze(maze.MAZE);
                }
                menu_Sec();
                cin >> subkey;
            }
        }
        menu_Fir();
        cin >> key;
    }

    return 0;
}