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
        leftchild = nullptr;  // initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class BinaryTree
{
public:
    node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing root to null
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

        // step 3 : make the left and right child of the new node point to null
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // step 4 : locate the node which will be the parent of the new node
        node *parent = nullptr;
        node *currentnode = nullptr;
        
        search(x, parent, currentnode);

        if (parent == nullptr)
        {
            ROOT = newNode;
            return;
        }

        if (x < parent->info)
        {
            parent->leftchild = newNode;
            return;
        }
        else if (x > parent->info)
        {
            parent->rightchild = newNode;
            return;
        }
    }

    void search(int element, node *&parent, node *&currentnode)
    {
        currentnode = ROOT;
        parent = nullptr;
        while ((currentnode != nullptr) && (currentnode->info != element))
        {
            parent = currentnode;
            if (element < currentnode->info)
                currentnode = currentnode->leftchild;
            else
                currentnode = currentnode->rightchild;
        }
    }

    void inorder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            inorder(ptr->leftchild);
            cout << ptr->info << " ";
            inorder(ptr->rightchild);
        }
    }

    void preorder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
    }


    void postorder(node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr)
        {
            postorder(ptr->leftchild);
            postorder(ptr->rightchild);
            cout << ptr->info << " "; // parent
        }
    }

    bool isEmpty()
    {
        // Checks if the tree is empty
        return ROOT == nullptr;
    }
};


