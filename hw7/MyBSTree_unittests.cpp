//
// Created by josh on 11/13/2025.
//

#include "MyBSTree.cpp"
#include "TreeNode.h"
#include "gtest/gtest.h"

TEST(MyBSTree_unittests, test_isEmpty_on_empty_tree) {
    MyBSTree<int> tree;
    EXPECT_TRUE(tree.isEmpty());
}

TEST(MyBSTree_unittests, test_size_on_empty_tree) {
    int expectedSize = 0;
    int expectedHeight = 0;
    MyBSTree<int> tree;
    EXPECT_EQ(tree.size(), expectedSize);
    EXPECT_EQ(tree.height(), expectedHeight);
}

TEST(MyBSTree_unittests, test_size_on_single_treenode_tree) {
    int expectedSize = 1;
    int expectedHeight = 1;
    MyBSTree<int> tree;
    tree.insert(1);
    EXPECT_EQ(tree.size(), expectedSize);
    EXPECT_EQ(tree.height(), expectedHeight);
}

TEST(MyBSTree_unittests, test_size_height_on_treenode_after_insertion_simple_int) {
    vector<int> inNodeVal = {1, 3, 2};
    int expectedHeight = 3;
    MyBSTree<int> tree;
    for (int val : inNodeVal) {
        tree.insert(val);
    }
    EXPECT_EQ(tree.size(), inNodeVal.size());
    EXPECT_EQ(tree.height(), expectedHeight);
}

TEST(MyBSTree_unittests, test_size_height_on_treenode_after_insertion_complex_int) {
    vector<int> inNodeVal = {7, 5, 9, 4, 6, 13, 10};
    int expectedHeight = 4;
    MyBSTree<int> tree;
    for (int val : inNodeVal) {
        tree.insert(val);
    }
    EXPECT_EQ(tree.size(), inNodeVal.size());
    EXPECT_EQ(tree.height(), expectedHeight);
}

TEST(MyBSTree_unittests, test_contains) {
    const int expectedLevel = 3;
    int expectedHeight = 3;
    vector<int> inNodeVal = {1, 3, 2};
    MyBSTree<int> tree;
    for (int val : inNodeVal) {
        tree.insert(val);
    }
    EXPECT_EQ(tree.contains(2), expectedLevel);
    EXPECT_EQ(tree.size(), inNodeVal.size());
    EXPECT_EQ(tree.height(), expectedHeight);
}

TEST(MyBSTree_unittests, test_remove) {
    vector<int> inNodeVal = {1, 3, 2};
    MyBSTree<int> tree;
    for (int val : inNodeVal) {
        tree.insert(val);
    }
    tree.remove(2);
    EXPECT_EQ(tree.size(), inNodeVal.size()-1);
    EXPECT_EQ(tree.height(), inNodeVal.size()-1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}