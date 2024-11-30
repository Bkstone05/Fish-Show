/*
    Name: Tree.cpp
    Purpose: runs the functions in tree.h
*/
#include <iostream>
#include "Tree.h"
using namespace std;

/*
    Function:   insert()
    Purpose:    to inserts into the tree
*/
void BinaryTree::insert(TreeNode *& nodePointer, TreeNode *& newNode)
{
    if (nodePointer == NULL)
    {
        nodePointer = newNode;
    }
    else if (newNode->value.getW() < nodePointer->value.getW())
    {
        insert(nodePointer->left, newNode); //to the left to the left to the left to the left
    }
    else
    {
        insert(nodePointer->right, newNode); //to the right to the right to the right to the right
    }
}


/*
    Function:   destroySubTree()
    Purpose:    to destroy a subtree
*/
void BinaryTree::destroySubTree(TreeNode * nodePointer)
{
    if(nodePointer)
    {
        if(nodePointer->left)
        {
            destroySubTree(nodePointer->left);
        }
        if(nodePointer->right)
        {
            destroySubTree(nodePointer->right);
        }

        delete nodePointer;
    }
}



/*
    Function:   deleteNode()
    Purpose:    to find the node to delete 
*/
void BinaryTree::deleteNode(Fish byeFish, TreeNode*& nodePointer)
{
    if(byeFish.getW() < nodePointer->value.getW())
    {
        deleteNode(byeFish, nodePointer->left);
    }
    else if(byeFish.getW() > nodePointer->value.getW())
    {
        deleteNode(byeFish, nodePointer->right);
    }
    else
    {
        makeDeletion(nodePointer); //calls function to perform deletion
    }
}


/*
    Function:   makeDeletion()
    Purpose:    to delete 
*/
void BinaryTree::makeDeletion(TreeNode *& nodePointer)
{
    TreeNode *tempNodePointer = NULL;

    if(nodePointer == NULL)
    {
        cout << "This Queen has no makeup on! Lets get her pampered!\n";
    }
    else if(nodePointer->right == NULL)
    {
        tempNodePointer = nodePointer;
        nodePointer = nodePointer->left;
        delete tempNodePointer;
    }
    else if(nodePointer->left == NULL)
    {
        tempNodePointer = nodePointer;
        nodePointer = nodePointer->right;
        delete tempNodePointer;
    }
    else //runs when the node has two children
    {
        tempNodePointer = nodePointer->right;

        while(tempNodePointer->left) //goes to be end of the left node
        {
            tempNodePointer = tempNodePointer->left;
        }
        //reattatches the left subtree
        tempNodePointer->left = nodePointer->left;
        tempNodePointer = nodePointer;
        //reattatches the right subtree
        nodePointer = nodePointer->right;
        delete tempNodePointer;
    }
}


/*
    Function:   preOrder()
    Purpose:    orders the fish in preorder
*/
void BinaryTree::preOrder(TreeNode * nodePointer) const
{
    if(nodePointer)
    {
        cout << "\n" ;
        nodePointer->value.printFish();
        preOrder(nodePointer->left);
        preOrder(nodePointer->right);

    }
}


/*
    Function:   postOrder()
    Purpose:    orders the fish in postorder
*/
void BinaryTree::postOrder(TreeNode * nodePointer) const
{

    if(nodePointer)
    {
        postOrder(nodePointer->left);
        postOrder(nodePointer->right);
        cout << "\n";
        nodePointer->value.printFish();
    }
}

/*
    Function:   inOrder()
    Purpose:    orders the fish in order
*/
void BinaryTree::inOrder(TreeNode* nodeptr) const
{
    if(nodeptr != NULL)
    {
        inOrder(nodeptr->left);
        cout << endl; 
        nodeptr->value.printFish();
        inOrder(nodeptr->right); 
    }
}


/*
    Function:   insertNode()
    Purpose:    to insert a node 
*/
void BinaryTree::insertNode(Fish name)
{
    TreeNode *newNode = NULL;

    if(this->searchNode(name))
    {
        cout << "\nGirllllll, " << name.getON() << " is already a queen" << endl;

    }
    else
    {
        newNode = new TreeNode;
        newNode->value = name;
        newNode->left = newNode->right = NULL;

        //insert the node
        insert(root, newNode);

        //numNodes gets incremented
        numNodes++;

        cout << "The " << name.getON() << " is a queen! Will they win?\n";
    }
}


/*
    Function:   remove()
    Purpose:    remove dat fish 
*/
void BinaryTree::remove(Fish name)
{
    deleteNode(name, root);
    numNodes--;
}


/*
    Function:   disqualify()
    Purpose:    disqualifies fish from race 
*/
void BinaryTree::disqualify(TreeNode* root, float dis)
{
    if(root->left == NULL && root->right == NULL)
    {
        return; 
    }
    if(root->value.getFS() < dis)
    {
        deleteNode(root->value, root);
        numNodes--;
        return; 
    }
    else
    {
        cout << "HERE";
        disqualify(root->left, dis);
    }
}


/*
    Function:   searchNode()
    Purpose:    searches for the node
*/
bool BinaryTree::searchNode(Fish target)
{
    TreeNode* nodePtr = root;

    while(nodePtr)
    {
        if(nodePtr->value.getW() == target.getW())
        {
            return true;
        }
        else if(target.getW() < nodePtr->value.getW())
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right; 
        }
    }
    return false; 
}


/*
    Function:   max()
    Purpose:    finds the max
*/
Fish BinaryTree::max(TreeNode* root)
{
    if(root == NULL)
    {
        cout << "No Queens are here? How is EVERYONE fashionably late?";
        return root->value;
    }
    if(root->right)
    {
        max(root->right);
    }
    return root->value;
}


/*
    Function:   min()
    Purpose:    finds the min
*/
Fish BinaryTree::min(TreeNode* root)
{
    if(root == NULL)
    {
        cout << "No Queens are here? How is EVERYONE fashionably late?";
        return root->value;
    }
    if(root->left)
    {
        min(root->left);
    }
   
    return root->value;
}