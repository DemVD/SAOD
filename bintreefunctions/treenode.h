#ifndef TREENODE_H
#define TREENODE_H


template <class T>
class treeNode{
private:
    treeNode<T> *_left;
    treeNode<T> *_right; // указатели на левый и правый элемент
public:
    T _data; // сами данные в узле
    treeNode(const T& item, treeNode<T> *lPtr=nullptr, treeNode<T> *rPtr=nullptr); // конструктор с пар-ми, указатели по ум.
    treeNode<T>* left() const;
    treeNode<T>* right() const;
    void setLeft(treeNode<T> *ptr);
    void setRight(treeNode<T> *ptr);
};

#include "treenode.cpp"

#endif // TREENODE_H
