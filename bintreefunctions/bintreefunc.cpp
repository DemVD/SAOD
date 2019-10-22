#include "bintreefunc.h"


template <class T>
treeNode<T>* createLeaf(const T& item){ // создание листа, левый правый сыновья = null
    treeNode<T>* newNode = new treeNode<T>(item);
    return newNode;
}

template <class T> // добавить новый лист
void addLeafFunc(treeNode<T>*& root, const T& item){
    treeNode<T> *tempNode = root;
    treeNode<T> *parent = nullptr;
    treeNode<T> *newNode;
    newNode = createLeaf(item);
    while(tempNode != nullptr){
        parent = tempNode;
        if(item < tempNode->_data){
            tempNode = tempNode->left();
        }
        else{
            tempNode = tempNode->right();
        }
    }
    if(parent == nullptr){
        root = newNode;
    }
    else{
        if(item < parent->_data){
            parent->setLeft(newNode);
        }
        else{
            parent->setRight(newNode);
        }
    }
}

template <class T> // глубина дерева
int maxDepth(treeNode<T>* node){
    if(node == nullptr){
        return -1;
    }
    else{
        int leftDepth = maxDepth(node->left());
        int rightDepth = maxDepth(node->right());
        if(leftDepth > rightDepth){
            return(leftDepth+1);
        }
        else{
            return(rightDepth+1);
        }
    }
}

template <class T> // нахождение минимального элемента в дереве (слева)
treeNode<T> *minValueNode(treeNode<T> *node){
    treeNode<T>* currNode = node;
    // цикл для нахождения самого левого листа
    while(currNode && currNode->left() != nullptr){
        currNode = currNode->left();
    }
    return currNode;
}

template <class T> // удалить узел
treeNode<T>* deleteNode(treeNode<T> *root, T key){
    if(root == nullptr){
        return root;
    }
    if(key < root->_data){ // если ключ < данных - искомый узел лежит в левом поддереве
        root->setLeft(deleteNode(root->left(), key));
    }
    else if(key > root->_data){ // если ключ > данных - искомый узел лежит в правом поддереве
        root->setRight(deleteNode(root->right(), key));
    }
    else{ // если ключ == данным в корне (или подкорне) - это узел, подлежащий удалению
        if(root->left() == nullptr){ // узел с 1 сыном, или без сыновей
            treeNode<T> *tempNode = root->right();
            delete root;
            return tempNode;
        }
        else if(root->right() == nullptr){
            treeNode<T> *tempNode = root->left();
            delete root;
            return tempNode;
        }
        // узел с двумя сыновьями: получить преемника из INORDER - минимальный в правом поддереве
        treeNode<T>* tempNode = minValueNode(root->right());
        root->_data = tempNode->_data; // скопировать содержимое преемника inorder в этот узел
        root->setRight(deleteNode(root->right(), tempNode->_data)); // удалить преемника inorder
    }
    return 0;
}

template <class T> // левый, узел, правый (IN ORDER)
void LNR(treeNode<T>* root, void visit(T& item)){
    if(root != nullptr){
        LNR(root->left(), visit);
        visit(root->_data);
        LNR(root->right());
    }
}

template <class T> // левый, правый, узел (POST ORDER) для удаления листов
void LRN(treeNode<T>* root, void visit(T& item)){
    if(root != nullptr){
        LRN(root->left());
        LRN(root->right());
        visit(root->_data);
    }
}

template <class T> // узел, левый, правый (PRE ORDER)
void NLR(treeNode<T> *root, void visit(T& item)){
    visit(root->_data);
    NLR(root->left());
    NLR(root->right());
}

template <class T> // visit (выводит содержимое дерева кучей)
void Print(T& item){
    cout<<item<<endl;
}

template <class T> // another visit (освобождает узел)
void freeNode(treeNode<T>* root){
    delete root;
}

template <class T> // удаляет дерево или поддерево целиком
void deleteTree(treeNode<T>* root){
    if(root != nullptr){
        LRN<T>(root, freeNode(root));
    }
}

template <class T> // считает кол-во листовых узлов в дереве или поддереве
int leafCount(treeNode<T>* root){
    if(root == nullptr){ //
        return 0;
    }
    if(root->left() == nullptr && root->right() == nullptr){
        return 1;
    }
    else{
        return leafCount(root->left()) + leafCount(root->right());
    }
}

template <class T> // вывод дерева по уровням
void printLevelOrder(const treeNode<T>* root){

}

template <class T> // печатает конкретный уровень
void printGivenLevel(const treeNode<T>* root, unsigned level){

}

/*
 * if(root == nullptr){ // tree is empty
        root = createLeaf(item);
    }
    else if(root->_data < item){ // tree is not empty = we have to really look where to create that leaf, left side first
        if(root->left() != nullptr){ // but we need to first check if there is a node connected to left pointer
            addLeafFunc(root->left(), item); // if there is - we recursively traverse the tree to find empty place for newLeaf
        }
        else{ // left pointer does indeed point into null, we just create a node right there!
            root->right()->_data = item;
        }
    }
    else if(item >= root->_data){ // if greater or equal than data in ptr, than we need to go right
        if(root->right() != nullptr){ // check if right pointer points to anything
            addLeafFunc(root->right(), item);
        }
        else{ // if it indeed is null = we create our leaf right there.
            root->right()->_data = item;
        }
    }
*/

/*
 * addLeafFunc old code
    if(root._data == nullptr){
        root = createLeaf(item);
    }
    else{
        bool run = true;
        treeNode<T> tempNode = createLeaf(item);
        do{
            if(tempNode._data == nullptr){
                tempNode._data = item;
                run = false;
            }
            else if(tempNode._data > item){
                tempNode = tempNode.left();
            }
            else if(tempNode._data <= item){
                tempNode = tempNode.right();
            }
            else{
            }
        }
        while(run);

    }

    leafCount old func
    if(root != nullptr){
        leafCount(root->left());
        leafCount(root->right());
        if(root->left() == nullptr && root->right() == nullptr){ // both childs null - leaf
            counter++;
        }
    }
    return counter;
*/
