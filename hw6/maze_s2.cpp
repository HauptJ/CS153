//
// Created by josh on 11/11/2025.
//

#include <iostream>
using namespace std;

// Reading "Null Terminated Character Arrays"

int main () {
    // Maze is a 2D array of characters
    char ** maze;

    // Read in size of Maze
    int rs;
    int cs;
    cin >> cs >> rs;
    cout << cs << " " << rs << endl;
    cin.ignore(); // to move read head to next line

    // Allocate Maze Array
    // Notice that an EXTRA cell is added to the columns
    // to account for NULL termination
    maze = new char*[rs];
    for (int k = 0; k < rs; k++) {
        maze[k] = new char[cs+1];
    }

    // Read Maze Array
    // Notice that we are reading each line as
    // a "NULL Terminating Character Array"
    for (int k = 0; k < rs; k++) {
        cin.getline(maze[k], cs+1);
    }

    // Print Maze Array
    for (int k = 0; k < rs; k++) {
        cout << maze[k] << endl;
    }

    // De-allocate Maze Array
    for (int k = 0; k < rs; k++) {
        delete [] maze[k];
    }
    delete [] maze;
}




