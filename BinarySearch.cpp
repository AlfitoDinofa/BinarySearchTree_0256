#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *leftchild;
    node *rightchild;

    node()
    {
        leftchild = nullptr;  // initialoze left child to the null
        rightchild = nullptr; // initilozr right child to the null
    }
};

class BinaryTree
{
public:
    node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // intializing root to null
    }
    void insert()
    {
        int x;
        cout << "masukkan nilai: ";
        cin >> x;

        // step 1 : allocate memory for the new node
        node *newNode = new node();

        // step 2 : assign value to the data field of new node
        newNode->info = x;
