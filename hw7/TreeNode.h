//
// Created by josh on 11/13/2025.
//

#ifndef TREENODE_H
#define TREENODE_H

template <class T>
struct TreeNode {
    T m_data;
    TreeNode* m_right;
    TreeNode* m_left;

    TreeNode() : m_data(nullptr), m_right(nullptr), m_left(nullptr) {}
    TreeNode(T data) : m_data(data), m_right(nullptr), m_left(nullptr) {}
    TreeNode(T data, TreeNode* right, TreeNode* left) : m_data(data), m_right(right), m_left(left) {}

    ~TreeNode() = default;
};


#endif //TREENODE_H