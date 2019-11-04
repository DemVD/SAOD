#include "binstree.h"

template <class T>
TreeNode<T>* BinSTree<T>::newNode(const T &item,
                         TreeNode<T> *lptr, TreeNode<T> *rptr){
    TreeNode<T> *ptr = new TreeNode<T>(item, lptr, rptr);
    if (ptr == nullptr){
        return nullptr;
    }
    return ptr;
}

template <class T>
void BinSTree<T>::deleteNode(TreeNode<T> *ptr){
    delete ptr;
}

template <class T>
BinSTree<T>::BinSTree(){
    this->_root = nullptr;
    this->_curr = nullptr;
    this->_size = 0;
}

template <class T>
TreeNode<T>* BinSTree<T>::findNodeAndParent(const T &item,
                                   TreeNode<T> *&parent) const{
    parent = nullptr;
    TreeNode<T>* curptr = _root;
    while (curptr){
        if (item == curptr->data){
            break;
        }
        else if (item < curptr->data){
            parent = curptr;
            curptr = curptr->Left();
        }
        else{
            parent = curptr;
            curptr = curptr->Right();
        }
    }
    return curptr;
}

template <class T> // redundant?
bool BinSTree<T>::checkKeyInTree(const T &item) const{
    return findNodeAndParent(item) ? true: false;
}

template <class T>
TreeNode<T>* BinSTree<T>::findNode(const T &item) const{
    TreeNode<T>* curptr = _root;
    while (curptr){
        if (item == curptr->data){
            break;
        }
        else if (item < curptr->data){
            curptr = curptr->Left();
        }
        else{
            curptr = curptr->Right();
        }
    }
    return curptr;
}

template <class T>
void BinSTree<T>::insertNode(const T &item){
    TreeNode<T> *node = newNode(item);
    if (_root == nullptr){
        _root = node;
        _curr = node;
    }
    else{
        _curr = _root;
        while (true){
            if (node->data >= _curr->data){
                TreeNode<T>* right = _curr->Right();
                if (right == nullptr){
                    _curr->setRight(node);
                    _curr = _curr->Right();
                    break;
                }
                else{
                    _curr = right;
                }
            }
            else{
                TreeNode<T>* left = _curr->Left();
                if (left == nullptr){
                    _curr->setLeft(node);
                    _curr = _curr->Left();
                    break;
                }
                else{
                    _curr = left;
                }
            }
        }
    }
    _size++; // !
}

template <class T>
void BinSTree<T>::update(const T &item){
    if (_curr){
        _curr->data = item;
    }
    else{
        insertNode(item);
    }
}


template <class T>
void BinSTree<T>::deleteNodeByKey(const T &item){
    if (_root){
        TreeNode<T> *targetParent = nullptr;
        TreeNode<T> *target = _root;
        TreeNode<T>* targetReplacer;
        target = findNode(item, targetParent);

        if (target == nullptr){
            return;
        }
        if ((target->Left() == nullptr) &&
                (target->Right() == nullptr)){
            targetReplacer = nullptr;
        }
        else if ((target->Left() != nullptr) &&
                 (target->Right() == nullptr)){
            targetReplacer = target->Left();
        }
        else if ((target->Left() == nullptr) && (target->Right() != nullptr)){
            targetReplacer = target->Right();
        }
        else{
            targetReplacer = target->Left();
            if (targetReplacer->Right()){
                TreeNode<T> *subTargetReplacer = targetReplacer;
                while (targetReplacer->Right()){
                    subTargetReplacer = targetReplacer;
                    targetReplacer = targetReplacer->Right();
                }
                if (targetReplacer->Left() == nullptr){
                    TreeNode<T> *t = nullptr;
                    subTargetReplacer->setRight(t);
                }
                else{
                    subTargetReplacer->setRight(targetReplacer->Left());
                }
                targetReplacer->setLeft(target->Left());
                targetReplacer->setRight(target->Right());
            }
            else{
                targetReplacer->setRight(target->Right());
            }
        }
        if (targetParent == nullptr){
            _root = targetReplacer;
        }
        else if (target->data < targetParent->data){
            targetParent->setLeft(targetReplacer);
        }
        else{
            targetParent->setRight(targetReplacer);
        }
        deleteNode(target);
        _size--;
        _curr = nullptr;
    }
}

template <class T>
void BinSTree<T>::clearTree(){
    deleteTree(_root);
    _root = nullptr;
    _size = 0;
    _curr = nullptr;
}

template <class T>
bool BinSTree<T>::checkIfEmpty() const{
    return _size == 0 ? true: false;
}

template <class T>
unsigned BinSTree<T>::size() const{
    return _size;
}

template <class T>
TreeNode<T>* BinSTree<T>::root() const{
    return _root;
}


template <class T>
void BinSTree<T>::deleteTree(TreeNode<T> *node){
    if (node){
        deleteTree(node->Left());
        deleteTree(node->Right());
        deleteNode(node);
    }
}
