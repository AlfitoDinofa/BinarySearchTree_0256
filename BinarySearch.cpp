#include <iostream>
using namespace std;

class node{
public:
    int info;
    node *leftchild;
    node *rightchild;
    
    node()
    {
        leftchild = nullptr; //initialoze left child to the null
        rightchild = nullptr; //initilozr right child to the null
    }

};  

class BinaryTree

