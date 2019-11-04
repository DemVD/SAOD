#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode{
private:
    TreeNode<T> *left;
    TreeNode<T> *right;
public:
    T data;
    TreeNode(const T &item, TreeNode<T>* lptr = nullptr,
             TreeNode<T>* rptr = nullptr);
    TreeNode<T>* Left() const;
    TreeNode<T>* Right() const;
    void setLeft(TreeNode<T> *lptr);
    void setRight(TreeNode<T> *rptr);
};

#include "treenode.cpp"
#endif // TREENODE_H
