// First traverse the right boundary and everytime check for that it is leaf node or not

// Traverse the leaf node

// Traverse ther right boundary then and check everytime for the leaf node

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isLeafNode(Node *node){
        if (node->left==nullptr && node->right==nullptr)
        return true;
        else return false;
    }

    void addLeftBoundary(Node *node,vector<int> &res){
        Node *currentNode = node->left;
        while(currentNode){
            if(!isLeafNode(currentNode))
            res.push_back(currentNode->data);
            if(currentNode->left)
            currentNode = currentNode->left;
            else
            currentNode = currentNode->right;
        }
    }
    
    void addRightBoundary(Node *node,vector<int> &res){
        vector<int> v;
        Node *currentNode = node->right;
        while(currentNode){
            if(!isLeafNode(currentNode))
            v.push_back(currentNode->data);
            if(currentNode->right)
            currentNode = currentNode->right;
            else
            currentNode = currentNode->left;
        }
        for(int i=v.size()-1;i>=0;i--){
            res.push_back(v[i]);
        }
    }
    
    void addLeafNode(Node *node, vector<int> &res){
        if(isLeafNode(node)){
            res.push_back(node->data);
            return;
        }
        
        if(node->left){
            addLeafNode(node->left,res);
        }
        
        if(node->right){
            addLeafNode(node->right,res);
        }
    }

    vector <int> boundary(Node *root){
        vector<int> result;
        
        if(root==nullptr) 
        return result;
        
        if(!isLeafNode(root))
        result.push_back(root->data);
        
        addLeftBoundary(root,result);
        addLeafNode(root,result);
        addRightBoundary(root,result);
        
        return result;
    }
};