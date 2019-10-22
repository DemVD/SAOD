#include "treenode.h"

template <class T>
treeNode<T>::treeNode(const T& item, treeNode<T> *lPtr, treeNode<T> *rPtr){
    this->_data = item;
    this->_left = lPtr;
    this->_right = rPtr;
}

template <class T>
treeNode<T>* treeNode<T>::left() const{
    return this->_left;
}

template <class T>
treeNode<T>* treeNode<T>::right() const{
    return this->_right;
}

template <class T>
void treeNode<T>::setLeft(treeNode<T> *ptr){
    this->_left = ptr;
}

template <class T>
void treeNode<T>::setRight(treeNode<T>* ptr){
    this->_right = ptr;
}
