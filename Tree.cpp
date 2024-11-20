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
    Purpose:    to delete a node 
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
        makeDeletion(nodePointer);
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
        cout << "Cannot delete an empty node.\n";
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
    Purpose:    orders the fish in increasing weight
*/
void BinaryTree::preOrder(TreeNode * nodePointer) const
{
    int counter = 0;
    if(nodePointer)
    {
        cout << counter+1 << ".\t" << nodePointer->value.getW() << endl;
        preOrder(nodePointer->left);
        preOrder(nodePointer->right);
        counter++;
    }
}


/*
    Function:   postOrder()
    Purpose:    orders the fish in decreasing weight
*/
void BinaryTree::postOrder(TreeNode * nodePointer) const
{
    int counter = 0;
    if(nodePointer)
    {
        postOrder(nodePointer->left);
        postOrder(nodePointer->right);
        cout << counter+1 << ".\t" << nodePointer->value.getW() << endl;
        counter ++;
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
        cout << "\nI'm sorry, " << name.getON() << " is already in the drag race" << endl;

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

        cout << "The " << name.getON() << " has been added to the drag race!\n";
    }
}


/*
    Function:   remove()
    Purpose:    remove dat bish 
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
    if(root->value.getFS() < dis)
    {
        deleteNode(root->value, root);
        numNodes--;
        return; 
    }
    else
    {
        disqualify(root->left, dis);
    }
}


/*
    Function:   searchNode()
    Purpose:    searches the node
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
        cout << "Nobody Has Entered The Drag Show Yet.";
        return;
    }
    if(root->right)
    {
        max(root->right);
    }
    else
    {
        return root->value;
    }
}


/*
    Function:   min()
    Purpose:    finds the min
*/
Fish BinaryTree::min(TreeNode* root)
{
    if(root == NULL)
    {
        cout << "Nobody Has Entered The Drag Show Yet.";
        return;
    }
    if(root->left)
    {
        min(root->left);
    }
    else
    {
        return root->value;
    }
}