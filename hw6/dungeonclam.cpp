//
// Created by josh on 11/11/2025.
//
#include "mazeObj.cpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

vector<mazeObj> loadMazes() {
    vector<mazeObj> mazes;

    char** maze;
    int cs, rs;
    do {
        cin >> cs >> rs;
        cin.ignore(); // to move read head to next line
        if (cs == 0 && rs == 0) {
            return mazes;
        }
        // Allocate Maze Array
        maze = new char*[rs];
        for (int k = 0; k < rs; k++) {
            maze[k] = new char[cs];
        }

        // Read Maze Array
        // Notice that we are reading *Character by Character*
        // and after every row, we need to read an extra character
        // to account for the 'end-of-line' character
        char dummy;
        for (int i = 0; i < rs; i++) {
            for (int j = 0; j < cs; j++) {
                cin.get(maze[i][j]);
            }
            cin.get(dummy); // read end-of-line
        }

        /*
        // Print Maze Array
        for (int i = 0; i < rs; i++) {
            for (int j = 0; j < cs; j++) {
                cout << maze[i][j];
            }
            cout << endl; // read end-of-line
        }
        */

        mazeObj maze_Obj(cs, rs, maze);
        mazes.push_back(maze_Obj);

    } while (true);
}

int main() {
    vector<mazeObj> mazes = loadMazes();
    cout << mazes.size() << endl;

    for (int i = 0; i < mazes.size(); i++) {
        cout << "Map : " << i << endl;
        //mazes[i].printMaze();
        pair<int, int> start = mazes[i].findStart();
        mazes[i].solve(start.first, start.second);
        mazes[i].printMaze();
        mazes[i].deleteMaze();
    }
    cout << endl;

    return 0;
}