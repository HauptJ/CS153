//
// Created by josh on 11/11/2025.
//

//#include "dungeonclam.cpp"
#include "mazeObj.cpp"
#include "utils.cpp"
#include <gtest\gtest.h>
#include <string>
#include <cstring> // for strcpy
#include <vector>
#include <iostream>
using namespace std;

const int IN_SIMPLE_CS = 11;
const int IN_SIMPLE_RS = 4;
const pair<int, int> IN_SIMPLE_START = make_pair(2, 1);
const int IN_COMPLEX_CS = 16;
const int IN_COMPLEX_RS = 10;
const pair<int, int> IN_COMPLEX_START = make_pair(5, 5);

// Convert vector<string> to char** (null-terminated)
char** vectorToCharArray(const std::vector<std::string>& strings) {
    // Allocate array of char* (+1 for null terminator)
    char** arr = new char*[strings.size() + 1];
    if (!arr) throw std::runtime_error("Memory allocation failed for char**");

    for (size_t i = 0; i < strings.size(); ++i) {
        // Allocate space for each C-string (+1 for '\0')
        arr[i] = new char[strings[i].size() + 1];
        if (!arr[i]) throw std::runtime_error("Memory allocation failed for char*");

        // Copy string content
        std::strcpy(arr[i], strings[i].c_str());
    }

    arr[strings.size()] = nullptr; // Null-terminate the array
    return arr;
}

/* For one strint -> char**
char* cstr = new char[str.size() + 1];
std::strcpy(cstr, str.c_str());
*/

// Free memory allocated for char**
void freeCharArray(char** arr) {
    if (!arr) return;
    for (int i = 0; arr[i] != nullptr; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

char** simpleInMaze() {
    vector<string> in_maze_strs;
    in_maze_strs.push_back("###########\n");
    in_maze_strs.push_back("#   #C#   #\n");
    in_maze_strs.push_back("#Z#     #E#\n");
    in_maze_strs.push_back("###########\n");
    return vectorToCharArray(in_maze_strs);
}

char** complexInMaze() {
    vector<string> in_maze_strs;
    in_maze_strs.push_back("################\n");
    in_maze_strs.push_back("#      #    # C#\n");
    in_maze_strs.push_back("# # #### ##   ##\n");
    in_maze_strs.push_back("# #      #######\n");
    in_maze_strs.push_back("# ###### #E    #\n");
    in_maze_strs.push_back("# #C#Z # ### ###\n");
    in_maze_strs.push_back("# # ## #     #C#\n");
    in_maze_strs.push_back("# # ## ####### #\n");
    in_maze_strs.push_back("#              #\n");
    in_maze_strs.push_back("################\n");
    return  vectorToCharArray(in_maze_strs);
}

TEST(mazeObj_unittests, constructor_simple_maze) {
    int in_cs = IN_SIMPLE_CS;
    int in_rs = IN_SIMPLE_RS;
    char** in_maze_char = simpleInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    EXPECT_EQ(actual_maze_obj.get_cs(), in_cs);
    EXPECT_EQ(actual_maze_obj.get_rs(), in_rs);
    EXPECT_EQ(actual_maze_obj.get_maze(), in_maze_char);
    freeCharArray(in_maze_char);
}

TEST(mazeObj_unittests, constructor_complex_maze) {
    int in_cs = IN_COMPLEX_CS;
    int in_rs = IN_COMPLEX_RS;
    char** in_maze_char = complexInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    EXPECT_EQ(actual_maze_obj.get_cs(), in_cs);
    EXPECT_EQ(actual_maze_obj.get_rs(), in_rs);
    EXPECT_EQ(actual_maze_obj.get_maze(), in_maze_char);
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, isExit_simple_maze) {
    int in_cs = IN_SIMPLE_CS;
    int in_rs = IN_SIMPLE_RS;
    char** in_maze_char = simpleInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);

    int in_i_exit_simple = 2;
    int in_j_exit_simple = 9;
    bool actual_bool = actual_maze_obj.isExit(in_i_exit_simple, in_j_exit_simple);
    EXPECT_EQ(actual_bool, true);
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, isValid_simple_maze) {
    int in_cs = IN_SIMPLE_CS;
    int in_rs = IN_SIMPLE_RS;
    char** in_maze_char = simpleInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);

    vector<pair<int, int>> in_maze_pairs;
    in_maze_pairs.push_back(make_pair(0, 0)); // # - wall /invalid
    in_maze_pairs.push_back(make_pair(1, 0)); // # - wall /invalid
    in_maze_pairs.push_back(make_pair(1, 1)); // empty - valid
    in_maze_pairs.push_back(make_pair(1, 5)); // C - clam /invalid

    vector<bool> expected_bools = { false, false, true, false };

    for (int i = 0; i < in_maze_pairs.size(); i++) {
        EXPECT_EQ(actual_maze_obj.isValid(in_maze_pairs[i].first, in_maze_pairs[i].second), expected_bools[i]);
    }
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, findStart_simple_maze) {

    int in_cs = IN_SIMPLE_CS;
    int in_rs = IN_SIMPLE_RS;
    char** in_maze_char = simpleInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    pair<int, int> actual_start = actual_maze_obj.findStart();
    EXPECT_EQ(actual_start.first, IN_SIMPLE_START.first);
    EXPECT_EQ(actual_start.second, IN_SIMPLE_START.second);
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, findStart_complex_maze) {

    int in_cs = IN_COMPLEX_CS;
    int in_rs = IN_COMPLEX_RS;
    char** in_maze_char = complexInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    pair<int, int> actual_start = actual_maze_obj.findStart();
    EXPECT_EQ(actual_start.first, IN_COMPLEX_START.first);
    EXPECT_EQ(actual_start.second, IN_COMPLEX_START.second);
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, solve_simple_maze) {
    int in_cs = IN_SIMPLE_CS;
    int in_rs = IN_SIMPLE_RS;
    char** in_maze_char = simpleInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    pair<int, int> actual_start = actual_maze_obj.findStart();
    bool actual_solve = actual_maze_obj.solve(actual_start.first, actual_start.second);
    EXPECT_EQ(actual_solve, true);
    actual_maze_obj.printMaze();
    freeCharArray(in_maze_char);
}

TEST(maze_obj_unittests, solve_complex_maze) {
    int in_cs = IN_COMPLEX_CS;
    int in_rs = IN_COMPLEX_RS;
    char** in_maze_char = complexInMaze();
    mazeObj actual_maze_obj(in_cs, in_rs, in_maze_char);
    pair<int, int> actual_start = actual_maze_obj.findStart();
    bool actual_solve = actual_maze_obj.solve(actual_start.first, actual_start.second);
    EXPECT_EQ(actual_solve, true);
    actual_maze_obj.printMaze();
    freeCharArray(in_maze_char);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}