//
// Created by josh on 11/11/2025.
//

#include <iostream>
using namespace std;

// Reading Character by Character

int main () {
    // Maze is a 2D array of characters
    char** maze; // REad in size of Maze

    // Read in size of Maze
    int cs;
    int rs;
    cin >> cs >> rs;
    cout << cs << " " << rs << endl;
    cin.ignore(); // to move read head to next line

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
    for (int k = 0; k < rs; k++) {
        for (int j = 0; j < cs; j++) {
            cin.get(maze[k][j]);
        }
        cin.get(dummy); // read end-of-line
    }

    // Print Maze Array
    for (int k = 0; k < rs; k++) {
        for (int j = 0; j < cs; j++) {
            cout << maze[k][j];
        }
        cout << endl; // read end-of-line
    }

    // De-allocate Maze Array
    for (int k = 0; k < rs; k++) {
        delete [] maze[k];
    }
    delete [] maze;
}