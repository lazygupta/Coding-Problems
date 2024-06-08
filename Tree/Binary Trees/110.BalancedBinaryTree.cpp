// Balanced Binary Tree is a height balanced tree
// In which (height of node of left subtree and right subtree) doesn't differs more than 1

// For Every Node = Height(leftSubtree) - Height(rightSubtree) <= 1


// Now we hcan do this by using previoud problem of finding height of a tree

// Intuition:-
// We will find height of every left and right subtree , if it differs more than 1 than return false
// Else we will check for the next node and continue


// T.C = O(N) * O(N) = O(N^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxmHeight(TreeNode *root){
        if(root==nullptr) return 0;
        
        int lh = maxmHeight(root->left);
        int rh = maxmHeight(root->right);

        return 1 + max(lh,rh);
    }

    bool isValid(TreeNode *root){
        if(root==nullptr) return true;

        int lh = maxmHeight(root->left);
        int rh = maxmHeight(root->right);

        if ( abs(lh-rh) > 1) return false; // Basically till here we can use this to check that node is valid or not

        bool left = isValid(root->left); // checks left subtree of node is valid or not
        bool right = isValid(root->right); // // checks right subtree of node is valid or not

        if ( right == false || left == false)  return false;

        return true;
    }
}

// Now we can optimise the above process of checking the valid subtree at the time of finding the height only


// Lets optimise

    int dfsheight(TreeNode *root){
        if(root==nullptr) return 0;

        int lh = dfsheight(root->left);
        if(lh==-1) return -1;

        int rh = dfsheight(root->right);
        if(rh==-1) return -1;

        if ( abs(lh-rh) > 1) return -1;

        return 1 + max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return dfsheight(root)==-1 ? false : true;
    }

// T.C = O(N)