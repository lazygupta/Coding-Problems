// We have to find maximum Path Sum
// Which path is maximum
// For every node we can check the value returned by its left path Sum and by its right path Sum
// And add both the value attained by the node value itself
// So we can get the Path Sum of that node
// Now we can do this in O(N^2), via runnign a loop for every node and check

// We will follow a basic modification ot previous problem where we were finding the width of the tree

// We will start from a node go to its left and return the value which should be maximum thru that path

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathSum(TreeNode *node,int &maximumSum){
        if(node == nullptr) return 0;

        int leftPathSum = max(0,pathSum(node->left,maximumSum));
        int rightPathSum = max(0,pathSum(node->right,maximumSum));

        maximumSum = max(maximumSum, leftPathSum + rightPathSum + node->val);

        return node->val + max(leftPathSum,rightPathSum);
    }

    int maxPathSum(TreeNode* root) {
        int maximumSum = INT_MIN;
        int maximumPathSum = pathSum(root,maximumSum);
        return maximumSum;
    }
};