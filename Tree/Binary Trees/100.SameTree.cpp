// We can check the both trees simltaneously

// We will check for:-
// If both trees are null, return true.
// Check if only one tree is null, return false.
// Now check the values of node
// Recursively check if the left subtrees of both trees are identical.
// Recursively check if the right subtrees of both trees are identical.
// Return the AND of the results after checking for both right and left

// T.C = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return  false;
    }
};