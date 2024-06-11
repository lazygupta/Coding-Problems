// Just find the maxlength everytime when u find left height and right height
// Just a sprevious problem of balanced tree 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfsHeight(TreeNode *node,int &maxLength){
        if(node == nullptr) return 0;

        int lh = dfsHeight(node->left,maxLength);
        int rh = dfsHeight(node->right,maxLength);

        maxLength = max(maxLength,lh+rh);

        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxLength=0;
        int maxHeight = dfsHeight(root,maxLength);
        return maxLength;
    }
};