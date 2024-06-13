// Same concept as Vertical traversal
// Imagine a line in every node vertically
// Insert only those values in map which appears on line very first
// or else ignore that line node


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> result;
        queue<pair<Node *,int>> q;
        map<int,Node*> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto element= q.front();
            q.pop();
            Node *node = element.first;
            int line = element.second;
            if(mpp.find(line) == mpp.end()); 
            // mpp[line]=node;
            mpp.insert({line,node});
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        for(auto it:mpp){
            result.push_back(it.second->data);
        }
        return result;
    }

};