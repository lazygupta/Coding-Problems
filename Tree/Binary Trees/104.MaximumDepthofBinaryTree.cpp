// Recursive way
// Go to right node find height store the height

// GO to left node find height store the height

// Store the maximum height out of two


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
    }
};