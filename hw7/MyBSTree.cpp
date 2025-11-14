//
// Created by josh on 11/13/2025.
//

#include "MyBSTree.h"
#include <string>
#include <vector>
using namespace std;

template <class T>
MyBSTree<T>::MyBSTree() {
    this->m_root = nullptr;
    this->m_size = 0;
    this->m_height = 0;
}

template<class T>
MyBSTree<T>::MyBSTree(TreeNode<T> *root) {
    this->m_root = root;
    this->m_size = 1;
    this->m_height = 1;
}

template<class T>
MyBSTree<T>::MyBSTree(TreeNode<T> *root, int size, int height) {
    this->m_root = root;
    this->m_size = size;
    this->m_height = height;
}

template<class T>
MyBSTree<T>::MyBSTree(const MyBSTree &cpy) {

    // set the new tree root to null
    m_root = nullptr;

    // copy the info from the other tree into this tree
    copyTree(m_root, cpy.m_root);
    this->m_size = cpy.m_size;
    this->m_height = cpy.m_height;
}


template<class T>
MyBSTree<T>::~MyBSTree() {
    deallocateTree(this->m_root);
}

template<class T>
MyBSTree<T> &MyBSTree<T>::operator=(const MyBSTree &obj) {
    // check if this tree is the same as the other tree on the other side of the operator
    if (this != &obj) {
        // if it is delete the current tree
        deallocateTree(this->m_root);

        // then create a new tree and point the root ptr at the new copied tree
        copyTree(this->m_root, obj.m_root);
        this->m_size = obj.m_size;
        this->m_height = obj.m_height;
    }

    // return the pointer of the new copied tree object
    return *this;
}

template<class T>
void MyBSTree<T>::copyTree(TreeNode<T> *&thisTreeNode, const TreeNode<T> *thatTreeNode) {
    // check if the current node of the other thee is null or not
    if (thatTreeNode != nullptr) {
        thisTreeNode = new TreeNode<T>(thatTreeNode->m_data, nullptr, nullptr);
        //thisTreeNode->m_data = thatTreeNode->m_data;
        //thisTreeNode->m_right = nullptr;
        //thisTreeNode->m_left = nullptr;

        // recursevely copy tree
        copyTree(thisTreeNode->m_left, thatTreeNode->m_left);
        copyTree(thisTreeNode->m_right, thatTreeNode->m_right);
    }
}

template<class T>
void MyBSTree<T>::deallocateTree(TreeNode<T> *&currNode) {
    //traverse through tree and delete nodes
    if (currNode != nullptr) {
        deallocateTree(currNode->m_left);
        deallocateTree(currNode->m_right);
        delete currNode;
    }
    currNode = nullptr;
}

// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise
template<class T>
bool MyBSTree<T>::isEmpty() const {
    return this->m_root == nullptr;
}

// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
template<class T>
void MyBSTree<T>::insert(const T& x) {
    // This passthrough is to enable the possibly switching out iterative and recursive implementations.
    insert_iter(x);
}

template<class T>
void MyBSTree<T>::insert_iter(const T& x) {
    // insert into empty tree
    if (this->m_root == nullptr) {
        this->m_root = new TreeNode<T>(x);
        ++this->m_height;
    }
    // insert into non-empty tree
    else {
        TreeNode<T>* current = this->m_root;
        while (true) {
            if (x < current->m_data) {
                if (current->m_left == nullptr) {
                    current->m_left = new TreeNode<T>(x);
                    if (this->contains(x) > this->m_height) {
                        this->m_height = this->contains(x);
                    }
                    break;
                }
                else {
                    current = current->m_left;
                }
            }
            else if (x > current->m_data) {
                if (current->m_right == nullptr) {
                    current->m_right = new TreeNode<T>(x);
                    if (this->contains(x) > this->m_height) {
                        this->m_height = this->contains(x);
                    }
                    break;
                }
                else {
                    current = current->m_right;
                }
            }
            else {
                // data already exists in the tree, do nothing
                break;
            }
        }
    }
    ++this->m_size;
}


// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
template<class T>
void MyBSTree<T>::remove(const T&x) {
    // This passthrough is to enable the possibly switching out iterative and recursive implementations.
    remove_iter(x);
}

template<class T>
void MyBSTree<T>::remove_iter(const T&x) {
    // does the Tree contain the data?
    if (this->contains(x) < 0) {
        return;
    }
    --this->m_size;

    TreeNode<T>* current = m_root;
    TreeNode<T>* parent = nullptr;

    // iterate to find the node to be removed
    while (current->m_data != x) {
        parent = current;
        if (x < current->m_data) {
            current = current->m_left;
        }
        else {
            current = current->m_right;
        }
    }

    // CASE 1 and CASE 3
    // check if the node to be deleted has only one child
    // Delete the node, and move its child up to take its place
    if (current->m_left == nullptr || current->m_right == nullptr) {

        // child will replace the node to be deleted
        TreeNode<T>* child;

        // if the left child does not exist
        if (current->m_left == nullptr) {
            child = current->m_right;
        }
        else {
            child = current->m_left;
        }

        // CASE 1
        // check if the node to be deleted is root
        if (parent == nullptr) {
            this->m_root = child;
            --this->m_height;
            return;
        }

        // check if the node to be deleted is the parent's left or right child and then replace the parent with the child
        if (current == parent->m_left) {
            parent->m_left = child;
            --this->m_height;
        }
        else {
            parent->m_right = child;
            --this->m_height;
        }

        // free the memory of the node to be deleted
        delete current;
    }

    // CASE 2
    // node to be deleted has two children
    else {
        // find the inorder successor
        TreeNode<T>* par = nullptr;
        TreeNode<T>* succ = current->m_right;
        while (succ->m_left != nullptr) {
            par = succ;
            succ = succ->m_left;
        }

        // check if the parent of the inorder
        // successor is the current or not
        // i.e. curr= the node which ahs the same data as the
        // given data to be deleted.
        // If it is not, then make the left child of its parent
        // equal to the inorder succssor's right child
        if (par != nullptr){
            par->m_left = succ->m_right;
        }

        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data to be deleted)
        // then make the right child of the node to be
        // deleted equal to the right child of
        // the inorder successor

        else {
            current->m_right = succ->m_right;
        }
        current->m_data = succ->m_data;

        delete succ;
    }
}

// Purpose: finds an element in the Tree
// Parameters: x is value to be found
// Returns:
//     If The tree contains x then
//         return N, the level of the node containing x
//     If The tree does not contains x then
//         return -N, where N is the level of the tree reached in the search
template <class T>
int MyBSTree<T>::contains(const T& x) const {
    TreeNode<T>* current = this->m_root;
    int level = 0;

    while (current != nullptr) {
        ++level;
        if (x == current->m_data) {
            return level; // Found the element
        }
        else if (x < current->m_data) {
            current = current->m_left;
        }
        else {
            current = current->m_right;
        }
    }
    return -level; // Element not found
}


// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree
template<typename T>
int MyBSTree<T>::size() const {
    return this->m_size;
}

// Purpose: Returns the height of the tree
// Returns: height the tree
template<typename T>
int MyBSTree<T>::height() const {
    return this->m_height;
};


template<class T>
const T &MyBSTree<T>::findMin() const {
    if (this->m_root == nullptr) {
        throw string("PANIC : Tree is empty!!");
    }
    TreeNode<T>* current = this->m_root;
    while (current->m_left != nullptr) {
        current = current->m_left;
    }
    return current->m_data;
}

template<class T>
const T &MyBSTree<T>::findMax() const {
    if (this->m_root == nullptr) {
        throw string("PANIC : Tree is empty!!");
    }
    TreeNode<T>* current = this->m_root;
    while (current->m_right != nullptr) {
        current = current->m_right;
    }
    return current->m_data;
}

// Purpose: Clears the Tree
// Postconditions: an empty Tree
template<class T>
void MyBSTree<T>::clear() {
    deallocateTree(this->m_root);
    this->m_root = nullptr;
    this->m_size = NULL;
    this->m_height = NULL;
}



template<class T>
void MyBSTree<T>::prettyPrintInOrder(const TreeNode<T>* t, int pad) const {
    string s(pad, ' ');
    if (t == NULL) {
        cout << endl;
    }
    else {
        prettyPrintInOrder(t->m_right, pad + 4);
        cout << s << t->m_data << endl;
        prettyPrintInOrder(t->m_left, pad + 4);
    }
}

template<class T>
void MyBSTree<T>::print() const {
    prettyPrintInOrder(m_root, 0);
}

template<class T>
void MyBSTree<T>::uglyPrintPreOrder(const TreeNode<T>* t) const {
    if (t == NULL) {
    }
    else {
        cout << t->m_data << endl;
        uglyPrintPreOrder(t->m_left);
        uglyPrintPreOrder(t->m_right);
    }
}

template<class T>
void MyBSTree<T>::prettyPrintPreOrder(const TreeNode<T>* t, int pad) const {
    string s(pad, ' ');
    if (t == NULL) {
        cout << endl;
    }
    else {
        cout << s << t->m_data << endl;
        prettyPrintPreOrder(t->m_left, pad + 4);
        prettyPrintPreOrder(t->m_right, pad + 4);
    }
}

template<class T>
void MyBSTree<T>::printPreOrder() const {
    //prettyPrintPreOrder(m_root, 0);
    uglyPrintPreOrder(m_root);
}


template<class T>
void MyBSTree<T>::uglyPrintPostOrder(const TreeNode<T>* t) const {
    if (t == NULL) {
    }
    else {
        uglyPrintPostOrder(t->m_left);
        uglyPrintPostOrder(t->m_right);
        cout << t->m_data << endl;
    }
}

template<class T>
void MyBSTree<T>::prettyPrintPostOrder(const TreeNode<T>* t, int pad) const {
    string s(pad, ' ');
    if (t == NULL) {
        cout << endl;
    }
    else {
        prettyPrintPostOrder(t->m_left, pad + 4);
        prettyPrintPostOrder(t->m_right, pad + 4);
        cout << s << t->m_data << endl;
    }
}

template<class T>
void MyBSTree<T>::printPostOrder() const {
    //prettyPrintPostOrder(m_root, 0);
    uglyPrintPostOrder(m_root);
}