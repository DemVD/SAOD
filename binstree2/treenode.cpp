#include "treenode.h"

template <class T>
TreeNode<T>::TreeNode(const T &item, TreeNode<T> *lptr,
                      TreeNode<T> *rptr){
    this->data = item;
    this->setLeft(lptr);
    this->setRight(rptr);
}

template <class T>
TreeNode<T>* TreeNode<T>::Left() const{
    return left;
}

template <class T>
TreeNode<T>* TreeNode<T>::Right() const{
    return right;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode<T> *lptr){
    left = lptr;
}

template <class T>
void TreeNode<T>::setRight(TreeNode<T> *rptr){
    right = rptr;
}
