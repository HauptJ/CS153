//
// Created by josh on 11/11/2025.
//

#include "mazeObj.h"
#include <vector>
#include <iostream>
using namespace std;

// unit test stringstream input
/*mazeObj::mazeObj(stringstream cs, stringstream rs, stringstream maze) {
    this->m_cs =
}*/

/*mazeObj::mazeObj() {

}*/

mazeObj::mazeObj(int cs, int rs, char** maze) {
    this->m_cs = cs;
    this->m_rs = rs;
    this->m_maze = maze;
}

bool mazeObj::isExit(int i, int j) {
    if (this->m_maze[i][j] == 'E') {
        return true;
    }
    return false;
}

bool mazeObj::isValid(int i, int j) {
    if (i < this->m_rs && j < this->m_cs && (this->m_maze[i][j] == ' ' || this->m_maze[i][j] == 'E')) {
        return true;
    }
    return false;
}

pair<int, int> mazeObj::findStart() {
    for (int i = 0; i < this->m_rs; i++) {
        for (int j = 0; j < this->m_cs; j++) {
            if (this->m_maze[i][j] == 'Z') {
                return pair<int, int>(i, j);
            }
        }
    }
}

void mazeObj::setPoint(int i, int j){
    this->m_maze[i][j] = '.';
}

void mazeObj::unsetPoint(int i, int j) {
    this->m_maze[i][j] = ' ';
}

bool mazeObj::solve(int i, int j) {
    vector<pair<int, int>> choices = {
        {-1, 0}, // N
        {1, 0}, // S
        {0, 1}, // E
        {0, -1} // W
    };
    for (int k = 0; k < choices.size(); k++) {
        if (isValid(i + choices[k].first, j + choices[k].second)) {
            //cout << "setting point: " << i + choices[k].first << ", " << j + choices[k].second << endl;
            if (!isExit(i + choices[k].first, j + choices[k].second)) {
                setPoint(i + choices[k].first, j + choices[k].second);
            }
            if (isExit(i + choices[k].first, j + choices[k].second)) {
                return true;
            }
            else {
                if (solve(i + choices[k].first, j + choices[k].second)) {
                    return true;
                } else {
                    //cout << "unsetting point: " << i + choices[k].first << ", " << j + choices[k].second << endl;
                    unsetPoint(i + choices[k].first, j + choices[k].second);
                }
            }
        }
    }
    return false;
}

void mazeObj::printMaze() const {

    // Print Maze Array
    for (int i = 0; i < m_rs; i++) {
        for (int j = 0; j < m_cs; j++) {
            cout << m_maze[i][j];
        }
        cout << endl; // read end-of-line
    }
    cout << endl; // read end-of-line
}

void mazeObj::deleteMaze() {
    // De-allocate Maze Array
    for (int k = 0; k < m_rs; k++) {
        delete [] m_maze[k];
    }
    delete [] m_maze;
}

int mazeObj::get_cs() const {
    return this->m_cs;
}

int mazeObj::get_rs() const {
    return this->m_rs;
}

void mazeObj::set_cs(int cs) {
    this->m_cs = cs;
}

void mazeObj::set_rs(int rs) {
    this->m_rs = rs;
}

char** mazeObj::get_maze() const {
    return this->m_maze;
}

void mazeObj::set_maze(char** maze) {
    this->m_maze = maze;
}