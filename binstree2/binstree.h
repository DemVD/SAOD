#ifndef BINSTREE_H
#define BINSTREE_H
#include "treenode.h"


template <class T>
class BinSTree{
protected:
    TreeNode<T> *_root;
    TreeNode<T> *_curr;
    unsigned _size;

    TreeNode<T>* newNode(const T &item, TreeNode<T> *lptr = nullptr,
                             TreeNode<T> *rptr = nullptr);
    void deleteNode(TreeNode<T> *ptr);
    TreeNode<T>* findNodeAndParent(const T &item, TreeNode<T> *&parent) const;
    void deleteTree(TreeNode<T> *node);

public:
    BinSTree();
    BinSTree<T>& operator = (const BinSTree<T> &tree);
    BinSTree<T>& operator =(BinSTree<T> &&tree);

    bool checkKeyInTree(const T &item) const;
    TreeNode<T>* findNode(const T &item) const;
    void insertNode(const T &item);
    void update(const T &item); // updates the current node
    void deleteNodeByKey(const T &item);
    void clearTree();
    bool checkIfEmpty() const;
    unsigned size() const;
    TreeNode<T>* root() const;
};

#include "binstree.cpp"
#endif // BINSTREE_H
