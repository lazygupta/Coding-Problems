// Same as Top View of a Tree
// Just a minor modification is that
// Whenever we get element at a line we replace the line nodeValue by that new valueNode


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        // We will be using BFS
        vector<int> result;
        if(root==nullptr) return result;
        queue<pair<int,Node*>> q;
        map<int,int> mpp;
        q.push({0,root});
        while(!q.empty()){
            auto queue_element = q.front();
            q.pop();
            int line = queue_element.first;
            Node *node = queue_element.second;
            mpp[line]=node->data; // Replace the line by new latest node data
            // And the new nodeData will be always the last node from bottom
            // Because its a level order traversal
            if(node->left) q.push({line-1,node->left});
            if(node->right) q.push({line+1,node->right});
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        
        return result;
    }
};