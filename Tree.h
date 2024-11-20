/*
    Name: Tree.h
    Purpose: Holds the class for the Binary Search Tree
*/

#ifndef Tree_H
#define Tree_H

#include "Fish.h"

class BinaryTree
{
    private:
        struct TreeNode
        {
            Fish value;
            TreeNode* left;
            TreeNode* right;
        };

        TreeNode* root;
        int numNodes;

        public:
        void insert(TreeNode *&, TreeNode *&);
        void deleteNode(Fish, TreeNode*);
        void makeDeletion(TreeNode *&);
        void fullDisplayInOrder(TreeNode*) const;
        void displayPreOrder(TreeNode*) const; //could need to be post Order TBH

        //constructor
        CreateBinaryTree()
        {
            root = NULL;
            numNodes = 0;
        }

        //destructor 
        ~CreateBinaryTree()
        {
            destroySubTree(root);
        }

};


#endif 
