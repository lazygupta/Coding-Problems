// Just assign each level nodes with index starting from 0;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxLength = INT_MIN;
        while (!q.empty()) {
            int size = q.size();
            int first,last;
            int minIndex = q.front().second; // Index of first node of a level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long int index = q.front().second-minIndex; // To make index starting from zero
                q.pop();
                if(i==0) first = index;
                if(i==size-1) last = index;
                if(node->left) q.push({node->left,2*index+1});
                if(node->right) q.push({node->right,2*index+2});
            }
            maxLength = max(maxLength, last-first+1);
        }
        return maxLength;
    }
};