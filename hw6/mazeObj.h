//
// Created by josh on 11/11/2025.
//

#ifndef HW6_MAZE_H
#define HW6_MAZE_H
#include <string>
using namespace std;

class mazeObj {

    int m_cs;
    int m_rs;
    char** m_maze;

    // reads in maze params from stdin
    //mazeObj();

    //mazeObj(stringstream cs, stringstream rs, stringstream maze);

public:
    mazeObj(int cs, int rs, char** maze);

    bool isExit(int i, int j);
    bool isValid(int i, int j);
    pair<int, int>findStart();
    void setPoint(int i, int j);
    void unsetPoint(int i, int j);
    bool solve(int i, int j);
    void printMaze() const;
    void deleteMaze();

    int get_cs() const;
    int get_rs() const;
    void set_cs(int cs);
    void set_rs(int rs);
    char** get_maze() const;
    void set_maze(char** maze);
};


#endif //HW6_MAZE_H