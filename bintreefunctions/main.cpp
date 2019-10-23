#include <QCoreApplication>
#include "bintreefunc.h"
#include <iostream>

using namespace std;


int main(){
    treeNode<int>* root = new treeNode<int>(40);
    addLeafFunc(root, 50);
    addLeafFunc(root, 30);
    cout<<root->_data<<endl;
    cout<<root->right()->_data<<endl;
    cout<<root->left()->_data<<endl;

    addLeafFunc(root, 60);
    cout<<root->right()->right()->_data<<endl;
    int d = maxDepth(root);
    cout<<endl<<d<<endl;
    int c = leafCount(root);
    cout<<endl<<"Leaf count: "<<c<<endl;

    printLevelOrder(root, d);

}
