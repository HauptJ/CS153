//
// Created by josh on 11/10/2025.
//

#include<iostream>
using namespace std;

// Reading String objects

int main() {
    // Maze is an array of strings
    string* maze;

    // Read in size of maze
    int cs;
    int rs;
    cin >> cs >> rs;
    cout << cs << " " <<  rs << endl;
    cin.ignore(); // to move read head to next line

    // Allocate Maze Array
    maze = new string[rs];

    // Read Maze
    // each row is a string;
    for (int k = 0; k < rs; k++) {
        getline(cin, maze[k]);
    }

    // Print Maze Array
    for (int k = 0; k < rs; k++) {
        cout << maze[k] << endl;
    }

    // De-allocate Maze Array
    delete[] maze;
}




