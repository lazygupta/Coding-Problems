// Insertion in BST

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    node* build ( vector<int> &v, int i){
        node *root = NULL;
        if (i < v.size()){
            root = newNode(v[i]);
        }
        else{
            return NULL;
        }
        i= 2*i;
        root->left = build(v, i+1);
        root->right = build(v, i+2);
        return root;
    }

    void create_tree(node* &root0, vector<int> &vec){
        //Your code goes here
        root0 = build(vec,0);
    }

};

// Inorder Traversal

void inOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        inOrder(node->left,v);
        v[0].push_back(node->data);
        inOrder(node->right,v);
    }

// PreOrder Traversal

void preOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        v[1].push_back(node->data);
        preOrder(node->left,v);
        preOrder(node->right,v);
    }

// postOrder Traversal


void postOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        postOrder(node->left,v);
        postOrder(node->right,v);
        v[2].push_back(node->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> v(3);
    preOrder(root,v);
    postOrder(root,v);
    inOrder(root,v);
    return v;
}

// Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> v;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};