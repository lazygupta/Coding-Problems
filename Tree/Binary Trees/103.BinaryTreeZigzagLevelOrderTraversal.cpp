// Same as Level order Traversal
// Dont do changes in traversal
// Just insert the node value in data structure in reverse way whenever you are in odd level

// Example insert in these way
// 1st Level - v[0]
// 2nd Level - v[1],v[0]
// 3rd Level - v[0],v[1],v[2]
// 4th Level - v[2],v[1],v[0]


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();

                int index = leftToRight ? i : size-i-1 ; // This is to check we are in odd level or even level

                v[index] = node->val;

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            leftToRight = !leftToRight; // After every level we change the boolean value
            result.push_back(v); 
        }
        return result;
    }
};