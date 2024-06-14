// Same as LC 100 Same Tree

// Just check for the LeftNode left is same as RightNode right

// Every right node will be equal to its left node in its mirror

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSame(TreeNode *nodeLeft,TreeNode *nodeRight){
        if(nodeLeft==nullptr && nodeRight==nullptr) 
            return true;

        if(nodeLeft==nullptr || nodeRight==nullptr) return nodeLeft==nodeRight;
        
        if(nodeLeft->val==nodeRight->val)
        return isSame(nodeLeft->left,nodeRight->right) && isSame(nodeLeft->right,nodeRight->left);

        return false;

    }

    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};