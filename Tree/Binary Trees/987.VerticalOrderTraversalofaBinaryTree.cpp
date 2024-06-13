#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; // Map with {col-coordinate,{row-coordinate,nodeValue}}
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int size = q.size();
            auto nodecoord = q.front();
            TreeNode *node = nodecoord.first;
            q.pop();
            int col = nodecoord.second.first;
            int row = nodecoord.second.second;
            nodes[col][row].insert(node->val);
            if(node->left != nullptr) q.push({node->left,{col-1,row+1}});
            if(node->right != nullptr) q.push({node->right,{col+1,row+1}});
        }

        vector<vector<int>> result;
        for(auto it1: nodes){
            vector<int> v;
            for(auto it2:it1.second){
                v.insert(v.end(),it2.second.begin(),it2.second.end());
            }
            result.push_back(v);
        }
        return result;
    }
};