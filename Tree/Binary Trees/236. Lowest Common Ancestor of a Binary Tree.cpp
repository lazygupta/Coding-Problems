#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    TreeNode* path(TreeNode *root,TreeNode *p,TreeNode *q){
        if(!root){
            return root;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode *left = path(root->left,p,q);
        TreeNode *right = path(root->right,p,q);
        if(left==nullptr) return right;
        else if(right== nullptr) return left;
        else return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return path(root,p,q);
    }
};
