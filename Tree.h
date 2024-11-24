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

        void insert(TreeNode *&, TreeNode *&);
        void destroySubTree(TreeNode *);
        void deleteNode(Fish, TreeNode*&);
        void makeDeletion(TreeNode *&);


        public:

        //constructor
        BinaryTree()
        {
            root = NULL;
            numNodes = 0;
        }

        void insertNode(Fish);
        void remove(Fish);
        void preOrder(TreeNode *) const;
		void postOrder(TreeNode *) const;
        bool searchNode(Fish target);
        void disqualify(TreeNode* root, float dis);
        Fish max(TreeNode* root); 
        Fish min(TreeNode* root);

        

        void displayPreOrder() const
        {
            preOrder(root);
        }

        void displayPostOrder() const
        {
            postOrder(root); 
        }

        int getNumNodes() const
        {
            return numNodes;
        }

        TreeNode* getRoot() const
        {
            return root; 
        }
        
        //destructor 
        ~BinaryTree()
        {
            destroySubTree(root);
        }
        

};


#endif 
