//
// Created by josh on 11/13/2025.
//

#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"
#include "TreeNode.h"

template <class T>
class MyBSTree : public AbstractBSTree<T> {
    TreeNode<T>* m_root;
    int m_size;
    int m_height;

public:
    MyBSTree();
    MyBSTree(TreeNode<T>* root);
    MyBSTree(TreeNode<T>* root, int size, int height);
    MyBSTree<T>& operator=(const MyBSTree &);
    MyBSTree(const MyBSTree &cpy);
    ~MyBSTree();

    void copyTree(TreeNode<T>*& thisTreeNode, const TreeNode<T>* thatTreeNode);
    void deallocateTree(TreeNode<T>*& thisNode);
    bool isEmpty() const override;

    void insert_iter(const T &x);
    void insert(const T &x) override;

    void remove_iter(const T &x);
    void remove(const T &x) override;

    void prettyPrintInOrder(const TreeNode<T>* t, int pad) const;
    void print() const override; // in order left -> root -> right

    void uglyPrintPreOrder(const TreeNode<T>* t) const;
    void prettyPrintPreOrder(const TreeNode<T>* t, int pad) const;
    void printPreOrder() const override; // root -> left -> right

    void uglyPrintPostOrder(const TreeNode<T>* t) const;
    void prettyPrintPostOrder(const TreeNode<T>* t, int pad) const;
    void printPostOrder() const override; // left -> right -> root

    int height() const override;
    int size() const override;
    const T& findMax() const override;
    const T& findMin() const override;
    int contains(const T &x) const override;
    void clear() override;

};


#endif //MYBSTREE_H