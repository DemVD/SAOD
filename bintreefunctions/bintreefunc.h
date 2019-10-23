#ifndef BINTREEFUNC_H
#define BINTREEFUNC_H
#include <iostream>
#include <queue>
#include "treenode.h"

using namespace std;

template <class T>
treeNode<T>* createLeaf(const T& item); // создать новый лист, левый и правый сыновья = null

template <class T>
void addLeafFunc(treeNode<T>*& root, const T& item); // добавить новый лист

template <class T>
int maxDepth(treeNode<T>* node); // глубина дерева

template <class T>
treeNode<T>* minValueNode(treeNode<T> *node); // нахождение минимального элемента в дереве (слева)

template <class T>
treeNode<T>* deleteNode(treeNode<T>* root, T key); // удалить узел

template <class T> // левый, узел, правый (IN ORDER)
void LNR(treeNode<T>* root, void visit(T& item));

template <class T> // левый, правый, узел (POST ORDER) (для удаления деревьев)
void LRN(treeNode<T>* root, void visit(T& item));

template <class T> // узел, левый, правый (PRE ORDER)
void NLR(treeNode<T> *root, void visit(T& item));

template <class T> // visit (посещение узла, печатает содержимое)
void Print(T& item);

template <class T> // another visit (освобождает узел)
void freeNode(treeNode<T>* root);

template <class T> // удаляет дерево или поддерево, начиная от корня
void deleteTree(treeNode<T>* root);

template <class T> // подсчет кол-ва листьев в дереве или поддереве
int leafCount(treeNode<T>* root);

template <class T> // вывод дерева по уровням
void printLevelOrder(const treeNode<T>* root, int height);

template <class T> // печатает конкретный уровень
void printGivenLevel(const treeNode<T>* root, int level);

#include "bintreefunc.cpp"
#endif // BINTREEFUNC_H
