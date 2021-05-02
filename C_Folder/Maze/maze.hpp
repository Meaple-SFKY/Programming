/*------------------------------  maze.hpp  -------------------------*/

#ifndef _MAZE_HPP_
#define _MAZE_HPP_

#include <fstream>
#include <iostream>
#include <sstream> 
#include <ctime>
#include <string>

#define SQUARE "██"
#define SPACE "  "
#define MYSELF "★★"
#define DOWNARROW "↓↓"
#define UPARROW "↑↑"
#define LEFTARRROW "←←"
#define RIGHTARROW "→→"
#define ENTRANCE "◉◉"
#define DESTINATION "▼▲"
#define WALLR 2
#define WALL 1
#define ROAD 0
#define READED 1
#define UNREADED 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define LEAVETYPE "leave"
#define FORKTYPE "fork"
#define BRANCHTYPE "branch"
#define WALLTYPE "wall"
#define UNREADTYPE "unread"
#define READEDTYPE "readed"
#define VISITEDTYPE "visited"
#define INITTYPE "init"
#define DIRECTIONUP "up"
#define DIRECTIONDOWN "down"
#define DIRECTIONLEFT "left"
#define DIRECTIONRIGHT "right"
#define DIRECTIONINIT "init"

using namespace std;

typedef struct point {
    int X_Locat;
    int Y_Locat;
} Point;

typedef struct {
    bool ifUp;
    bool ifDown;
    bool ifLeft;
    bool ifRight;
} Continuity;

typedef struct {
    string type;
    string state;
    Continuity continuity;
} Node;

typedef struct {
    Node priorNode;
    Node nextNode;
    Point* passBy;
} Edge;

typedef struct {
    int** array;
    int** read;
    Node** graph;
    Point startPoint;
    Point endPoint;
    int size;
    int pointNum;
} mazeInfo;

class Maze {
private:
    int getSeed(void);
    string mode;

    bool readJudge(mazeInfo maze, Point pointReadJudge);
    bool around(mazeInfo maze, Point pointAround);
    void setPointNum(void);
    bool ifIsEntrance(int i, int j);
    bool ifIsDedication(int i, int j);
    Point unreadedEntrance(int i, int j);
    Point unreadedBranch(int i, int j);
    Point unreadedFork(int i, int j);
    Point unreadedLeave(int i, int j);
    Point readedEntrance(int i, int j);
    Point readedBranch(int i, int j);
    Point readedFork(int i, int j);

public:
    mazeInfo MAZE;

    Maze(int size);
    Maze(string name);
    ~Maze() {};

    void printMaze(mazeInfo maze);
    void setStartPoint(Point pointStartPoint);
    void setEndPoint(Point pointStartPoint);
    void editWallPoint(Point pointSetWall);
    void editRoadPoint(Point pointSetRoad);
    void openpath(mazeInfo& maze, Point pointOpenPath);
    void setInfoFromFile(string name);
    void setGraphFromArray(void);
    void getPath(void);
};

Maze::Maze(int size) {
    MAZE.size = size;
    Point pointOpenPath;

    pointOpenPath.X_Locat = 1;
    pointOpenPath.Y_Locat = 1;

    if (MAZE.size % 2 == 0) {
        MAZE.size++;
    }

    cout << "Now its size is " << MAZE.size << " * " << MAZE.size << "......" << endl;
    int** a = new int* [MAZE.size];
    int** b = new int* [MAZE.size];
    for (int i = 0; i < MAZE.size; i++) {
        a[i] = new int[MAZE.size];
        b[i] = new int[MAZE.size];
    }
    MAZE.array = a;
    MAZE.read = b;

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            MAZE.array[i][j] = WALL;
            MAZE.read[i][j] = UNREADED;
        }
    }
    for (int i = 1; i < MAZE.size - 1; i += 2) {
        for (int j = 1; j < MAZE.size - 1; j += 2) {
            MAZE.array[i][j] = WALLR;
        }
    }

    MAZE.startPoint.X_Locat = 1;
    MAZE.startPoint.Y_Locat = 1;
    MAZE.endPoint.X_Locat = MAZE.size - 2;
    MAZE.endPoint.Y_Locat = MAZE.size - 2;

    openpath(MAZE, pointOpenPath);
}

Maze::Maze(string name) {
    setInfoFromFile(name);
}

int Maze::getSeed(void) {
    return rand() % 4;
}

void Maze::setGraphFromArray(void) {
    MAZE.graph = new Node* [MAZE.size];

    for (int i = 0; i < MAZE.size; i++) {
        MAZE.graph[i] = new Node[MAZE.size];
    }

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            MAZE.graph[i][j].type = WALLTYPE;
            MAZE.graph[i][j].state = INITTYPE;
            MAZE.graph[i][j].continuity.ifUp = false;
            MAZE.graph[i][j].continuity.ifDown = false;
            MAZE.graph[i][j].continuity.ifLeft = false;
            MAZE.graph[i][j].continuity.ifRight = false;
        }
    }

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            int temp = 0;
            if (MAZE.array[i][j] == ROAD) {
                if (MAZE.array[i][j - 1] == ROAD) {
                    MAZE.graph[i][j].continuity.ifLeft = true;
                    temp++;
                }
                if (MAZE.array[i - 1][j] == ROAD) {
                    MAZE.graph[i][j].continuity.ifUp = true;
                    temp++;
                }
                if (MAZE.array[i][j + 1] == ROAD) {
                    MAZE.graph[i][j].continuity.ifRight = true;
                    temp++;
                }
                if (MAZE.array[i + 1][j] == ROAD) {
                    MAZE.graph[i][j].continuity.ifDown = true;
                    temp++;
                }
                if (temp == 1) {
                    MAZE.graph[i][j].type = LEAVETYPE;
                }
                else if (temp == 2) {
                    MAZE.graph[i][j].type = BRANCHTYPE;
                }
                else if (temp == 3 || temp == 4){
                    MAZE.graph[i][j].type = FORKTYPE;
                }
                else {

                }
                MAZE.graph[i][j].state = UNREADTYPE;
            }
        }
    }

    cout << MAZE.graph[2][5].continuity.ifLeft << endl;
}

bool Maze::readJudge(mazeInfo maze, Point pointReadJudge) {
    if (maze.read[pointReadJudge.X_Locat][pointReadJudge.Y_Locat] == READED) {
        return true;
    }
    else {
        return false;
    }
}

bool Maze::around(mazeInfo maze, Point pointAround) {
    if (((pointAround.X_Locat > 2) && (maze.array[pointAround.X_Locat - 2][pointAround.Y_Locat] == WALLR)) || ((pointAround.X_Locat < maze.size - 3) && (maze.array[pointAround.X_Locat + 2][pointAround.Y_Locat] == WALLR))
        || ((pointAround.Y_Locat > 2) && (maze.array[pointAround.X_Locat][pointAround.Y_Locat - 2] == WALLR)) || ((pointAround.Y_Locat < maze.size - 3) && (maze.array[pointAround.X_Locat][pointAround.Y_Locat + 2] == WALLR)))
    {
        return true;
    }
    return false;
}

void Maze::openpath(mazeInfo& maze, Point pointOpenPath) {
    if (pointOpenPath.X_Locat % 2 == 0) {
        if (pointOpenPath.X_Locat == 0) {
            pointOpenPath.X_Locat++;
        }
        else {
            pointOpenPath.X_Locat--;
        }
    }
    if (pointOpenPath.Y_Locat % 2 == 0) {
        if (pointOpenPath.Y_Locat == 0) {
            pointOpenPath.Y_Locat++;
        }
        else {
            pointOpenPath.Y_Locat--;
        }
    }

    while (1) {
        if (around(maze, pointOpenPath) == false) {
            return;
        }
        else {
            maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
            while (1) {
                int temp = getSeed();
                if (temp == UP && pointOpenPath.X_Locat > 2 && (maze.array[pointOpenPath.X_Locat - 2][pointOpenPath.Y_Locat] == WALLR)) {
                    pointOpenPath.X_Locat -= 2;
                    maze.array[pointOpenPath.X_Locat + 1][pointOpenPath.Y_Locat] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == DOWN && pointOpenPath.X_Locat < maze.size - 3 && (maze.array[pointOpenPath.X_Locat + 2][pointOpenPath.Y_Locat] == WALLR)) {
                    pointOpenPath.X_Locat += 2;
                    maze.array[pointOpenPath.X_Locat - 1][pointOpenPath.Y_Locat] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == LEFT && pointOpenPath.Y_Locat > 2 && (maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat - 2] == WALLR)) {
                    pointOpenPath.Y_Locat -= 2;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat + 1] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else if (temp == RIGHT && pointOpenPath.Y_Locat < maze.size - 3 && (maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat + 2] == WALLR)) {
                    pointOpenPath.Y_Locat += 2;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat - 1] = ROAD;
                    maze.array[pointOpenPath.X_Locat][pointOpenPath.Y_Locat] = ROAD;
                }
                else {
                    break;
                }
                openpath(maze, pointOpenPath);
            }
        }
    }
}

void Maze::setPointNum(void) {
    int num = 0;

    for (int i = 0; i < MAZE.size; i++) {
        for (int j = 0; j < MAZE.size; j++) {
            if (MAZE.array[i][j] == ROAD) {
                num++;
            }
        }
    }

    MAZE.pointNum = num;
}

void Maze::printMaze(mazeInfo maze) {
    for (int i = 0; i < maze.size; i++) {
        if (i < 10) {
            cout << i << " ";
        }
        else {
            cout << i;
        }
    }
    cout << endl;

    for (int x = 0; x < maze.size; x++) {
        for (int y = 0; y < maze.size; y++) {
            if (x == MAZE.startPoint.X_Locat && y == MAZE.startPoint.Y_Locat) {
                cout << ENTRANCE;
            }
            else if (x == MAZE.endPoint.X_Locat && y == MAZE.endPoint.Y_Locat) {
                cout << DESTINATION;
            }
            else if (maze.graph[x][y].type == WALLTYPE) {
                cout << SQUARE;
            }
            else {
                if (MAZE.graph[x][y].state == READEDTYPE) {
                    cout << "01";
                }
                else {
                    cout << SPACE;
                }
            }
        }
        cout << " " << x << endl;
    }
}

void Maze::setStartPoint(Point start) {
    if (MAZE.array[start.X_Locat][start.Y_Locat] == WALL) {
        cout << "The entrance is already part of the wall, please reset the entrance..." << endl;
    }
    else {
        MAZE.startPoint.X_Locat = start.X_Locat;
        MAZE.startPoint.Y_Locat = start.Y_Locat;
    }
}

void Maze::setEndPoint(Point end) {
    if (MAZE.array[end.X_Locat][end.Y_Locat] == WALL) {
        cout << "The destination is already part of the wall, please reset the destination..." << endl;
    }
    else {
        MAZE.endPoint.X_Locat = end.X_Locat;
        MAZE.endPoint.Y_Locat = end.Y_Locat;
    }
}

void Maze::editWallPoint(Point pointSetWall) {
    MAZE.array[pointSetWall.X_Locat][pointSetWall.Y_Locat] = WALL;
}

void Maze::editRoadPoint(Point pointSetRoad) {
    MAZE.array[pointSetRoad.X_Locat][pointSetRoad.Y_Locat] = ROAD;
}

void Maze::setInfoFromFile(string name) {
    string fileName = name;
    ifstream infoFile(fileName);
    string temp;
    int j = 0, k = 0, size;
    stringstream stringToInteger;

    if (!infoFile.is_open()) {
        cout << "File failed to open." << endl;
        return;
    }

    while (getline(infoFile, temp)) {
        if (k == 0) {
            stringToInteger.clear();
            stringToInteger << temp;
            stringToInteger >> size;
            MAZE.size = size;
            MAZE.array = new int* [MAZE.size];
            for (int i = 0; i < size; i++) {
                MAZE.array[i] = new int[MAZE.size];
            }
        }
        else {
            for (int i = 0; i < temp.length(); i++) {
                stringToInteger.clear();
                stringToInteger << temp.substr(i, 1);
                stringToInteger >> MAZE.array[j][i];
            }
            j++;
        }
        k++;
    }

    infoFile.close();
}

bool Maze::ifIsEntrance(int i, int j) {
    if (i == MAZE.startPoint.X_Locat && j == MAZE.startPoint.Y_Locat) {
        return true;
    }
    else {
        return false;
    }
}

bool Maze::ifIsDedication(int i, int j) {
    if (i == MAZE.endPoint.X_Locat && j == MAZE.endPoint.Y_Locat) {
        return true;
    }
    else {
        return false;
    }
}

Point Maze::unreadedEntrance(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].type == LEAVETYPE) {
        if (MAZE.graph[i][j].continuity.ifLeft == true) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j].continuity.ifUp == true) {
            newPoint.X_Locat = i - 1;
            newPoint.X_Locat = j;
        }
        else if (MAZE.graph[i][j].continuity.ifRight == true) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].type == BRANCHTYPE) {
        if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifRight == true) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j].continuity.ifUp == true && MAZE.graph[i][j].continuity.ifDown == true) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifUp == true) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifDown == true) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i][j].continuity.ifRight == true && MAZE.graph[i][j].continuity.ifUp == true) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
    }
    else if (MAZE.graph[i][j].type == FORKTYPE) {
        if (MAZE.graph[i][j].continuity.ifLeft == false) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i][j].continuity.ifUp == false) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j].continuity.ifRight == false) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i][j].continuity.ifDown == false) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else {

    }
    MAZE.graph[i][j].state = READEDTYPE;

    return newPoint;
}

Point Maze::unreadedBranch(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifRight == true) {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifUp == true && MAZE.graph[i][j].continuity.ifDown == true) {
        if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifUp == true) {
        if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifDown == true) {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifRight == true && MAZE.graph[i][j].continuity.ifUp == true) {
        if (MAZE.graph[i][j + 1].state == READEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
    }
    else {
        if (MAZE.graph[i][j + 1].state == READEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
    }
    MAZE.graph[i][j].state = READEDTYPE;

    return newPoint;
}

Point Maze::unreadedFork(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].continuity.ifLeft == false) {
        if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i][j + 1].state == READEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifRight == false) {
        if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i + 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifUp == false) {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i + 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifDown == false) {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i][j + 1].state == READEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    MAZE.graph[i][j].state = READEDTYPE;

    return newPoint;
}

Point Maze::unreadedLeave(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].continuity.ifLeft == true) {
        newPoint.X_Locat = i;
        newPoint.Y_Locat = j - 1;
    }
    else if (MAZE.graph[i][j].continuity.ifRight == true) {
        newPoint.X_Locat = i;
        newPoint.Y_Locat = j + 1;
    }
    else if (MAZE.graph[i][j].continuity.ifUp == true) {
        newPoint.X_Locat = i - 1;
        newPoint.Y_Locat = j;
    }
    else {
        newPoint.X_Locat = i + 1;
        newPoint.Y_Locat = j;
    }
    MAZE.graph[i][j].state = VISITEDTYPE;

    return newPoint;
}

Point Maze::readedBranch(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifRight == true) {
        if (MAZE.graph[i][j - 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifUp == true && MAZE.graph[i][j].continuity.ifDown == true) {
        if (MAZE.graph[i - 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifUp == true) {
        if (MAZE.graph[i - 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifLeft == true && MAZE.graph[i][j].continuity.ifDown == true) {
        if (MAZE.graph[i][j - 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifRight == true && MAZE.graph[i][j].continuity.ifUp == true) {
        if (MAZE.graph[i][j + 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
    }
    else {
        if (MAZE.graph[i][j + 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
    }
    MAZE.graph[i][j].state = VISITEDTYPE;

    return newPoint;
}

Point Maze::readedFork(int i, int j) {
    Point newPoint;
    if (MAZE.graph[i][j].continuity.ifLeft == false) {
        if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i - 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i - 1][j].state == VISITEDTYPE && MAZE.graph[i][j + 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i - 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifRight == false) {
        if (MAZE.graph[i - 1][j].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j - 1].state == VISITEDTYPE && MAZE.graph[i - 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i - 1][j].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifUp == false) {
        if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j - 1].state == VISITEDTYPE && MAZE.graph[i][j + 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i + 1][j].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else if (MAZE.graph[i + 1][j].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else {
            newPoint.X_Locat = i + 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
    }
    else if (MAZE.graph[i][j].continuity.ifDown == false) {
        if (MAZE.graph[i - 1][j].state == VISITEDTYPE && MAZE.graph[i][j + 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
        }
        else if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == UNREADTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
        }
        else if (MAZE.graph[i][j - 1].state == VISITEDTYPE && MAZE.graph[i - 1][j].state == UNREADTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
        }
        else if (MAZE.graph[i - 1][j].state == VISITEDTYPE && MAZE.graph[i][j + 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j - 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else if (MAZE.graph[i][j + 1].state == VISITEDTYPE && MAZE.graph[i][j - 1].state == VISITEDTYPE) {
            newPoint.X_Locat = i - 1;
            newPoint.Y_Locat = j;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
        else {
            newPoint.X_Locat = i;
            newPoint.Y_Locat = j + 1;
            MAZE.graph[i][j].state = VISITEDTYPE;
        }
    }
    else {
        if (MAZE.graph[i][j - 1].state == READEDTYPE) {
            if (MAZE.graph[i - 1][j].state == VISITEDTYPE) {
                if (MAZE.graph[i][j + 1].state == VISITEDTYPE) {
                    if (MAZE.graph[i + 1][j].state == VISITEDTYPE) {
                        newPoint.X_Locat = i;
                        newPoint.Y_Locat = j - 1;
                        MAZE.graph[i][j].state = VISITEDTYPE;
                    }
                    else {
                        newPoint.X_Locat = i + 1;
                        newPoint.Y_Locat = j;
                    }
                }
                else {
                    newPoint.X_Locat = i;
                    newPoint.Y_Locat = j + 1;
                }
            }
            else {
                newPoint.X_Locat = i - 1;
                newPoint.Y_Locat = j;
            }
        }
        else if (MAZE.graph[i - 1][j].state == READEDTYPE) {
            if (MAZE.graph[i][j + 1].state == VISITEDTYPE) {
                if (MAZE.graph[i + 1][j].state == VISITEDTYPE) {
                    if (MAZE.graph[i][j - 1].state == VISITEDTYPE) {
                        newPoint.X_Locat = i - 1;
                        newPoint.Y_Locat = j;
                        MAZE.graph[i][j].state = VISITEDTYPE;
                    }
                    else {
                        newPoint.X_Locat = i;
                        newPoint.Y_Locat = j - 1;
                    }
                }
                else {
                    newPoint.X_Locat = i + 1;
                    newPoint.Y_Locat = j;
                }
            }
            else {
                newPoint.X_Locat = i;
                newPoint.Y_Locat = j + 1;
            }
        }
        else if (MAZE.graph[i][j + 1].state == READEDTYPE) {
            if (MAZE.graph[i + 1][j].state == VISITEDTYPE) {
                if (MAZE.graph[i][j - 1].state == VISITEDTYPE) {
                    if (MAZE.graph[i - 1][j].state == VISITEDTYPE) {
                        newPoint.X_Locat = i;
                        newPoint.Y_Locat = j + 1;
                        MAZE.graph[i][j].state = VISITEDTYPE;
                    }
                    else {
                        newPoint.X_Locat = i - 1;
                        newPoint.Y_Locat = j;
                    }
                }
                else {
                    newPoint.X_Locat = i;
                    newPoint.Y_Locat = j - 1;
                }
            }
            else {
                newPoint.X_Locat = i + 1;
                newPoint.Y_Locat = j;
            }
        }
        else {
            if (MAZE.graph[i][j - 1].state == READEDTYPE) {
                if (MAZE.graph[i - 1][j].state == VISITEDTYPE) {
                    if (MAZE.graph[i][j + 1].state == VISITEDTYPE) {
                        newPoint.X_Locat = i + 1;
                        newPoint.Y_Locat = j;
                        MAZE.graph[i][j].state = VISITEDTYPE;
                    }
                    else {
                        newPoint.X_Locat = i;
                        newPoint.Y_Locat = j + 1;
                    }
                }
                else {
                    newPoint.X_Locat = i - 1;
                    newPoint.Y_Locat = j;
                }
            }
            else {
                newPoint.X_Locat = i;
                newPoint.Y_Locat = j - 1;
            }
        }
    }

    return newPoint;
}

void Maze::getPath(void) {
    int i = MAZE.startPoint.X_Locat;
    int j = MAZE.startPoint.Y_Locat;
    cout << i << " " << j << endl;
    Point newPoint;
    while (ifIsDedication(i, j) == false) {
        if (ifIsEntrance(i, j) == true) {
            newPoint = unreadedEntrance(i, j);
            i = newPoint.X_Locat;
            j = newPoint.Y_Locat;
        }
        else if (MAZE.graph[i][j].type == BRANCHTYPE) {
            if (MAZE.graph[i][j].state == UNREADTYPE) {
                newPoint = unreadedBranch(i, j);
                i = newPoint.X_Locat;
                j = newPoint.Y_Locat;
            }
            else {
                newPoint = readedBranch(i, j);
                i = newPoint.X_Locat;
                j = newPoint.Y_Locat;
            }
        }
        else if (MAZE.graph[i][j].type == FORKTYPE) {
            if (MAZE.graph[i][j].state == UNREADTYPE) {
                newPoint = unreadedFork(i, j);
                i = newPoint.X_Locat;
                j = newPoint.Y_Locat;
            }
            else {
                newPoint = readedFork(i, j);
                i = newPoint.X_Locat;
                j = newPoint.Y_Locat;
            }
        }
        else if (MAZE.graph[i][j].type == LEAVETYPE) {
            newPoint = unreadedLeave(i, j);
            i = newPoint.X_Locat;
            j = newPoint.Y_Locat;
        }
        else {

        }
    }
    cout << i << " " << j << endl;
}

void menu_Fir(void) {
    for (int i = 0; i < 20; i++) {
        cout << SQUARE;
    }
    cout << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    cout << SQUARE << "                MAZE                " << SQUARE << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    cout << SQUARE << "        Please select a mode        " << SQUARE << endl;
    cout << SQUARE << "        1. Randomly generated       " << SQUARE << endl;
    cout << SQUARE << "        2. Generate from file       " << SQUARE << endl;
    cout << SQUARE << "        3. Exit                     " << SQUARE << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    for (int i = 0; i < 20; i++) {
        cout << SQUARE;
    }
    cout << endl;
}

void menu_Sec(void) {
    for (int i = 0; i < 20; i++) {
        cout << SQUARE;
    }
    cout << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    cout << SQUARE << "                MAZE                " << SQUARE << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    cout << SQUARE << "        Please select a mode        " << SQUARE << endl;
    cout << SQUARE << "        1. Edit the MAZE            " << SQUARE << endl;
    cout << SQUARE << "        2. Print the MAZE           " << SQUARE << endl;
    cout << SQUARE << "        3. Print the PATH           " << SQUARE << endl;
    cout << SQUARE << "        4. Exit                     " << SQUARE << endl;
    cout << SQUARE << "                                    " << SQUARE << endl;
    for (int i = 0; i < 20; i++) {
        cout << SQUARE;
    }
    cout << endl;
}

#endif