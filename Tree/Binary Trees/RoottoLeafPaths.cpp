// fantastic Question
// It is so simple to draw its recursive solution
// But we have to be acreful about the edge cases

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void pathToLeaf(Node *root,vector<vector<int>> &res,vector<int> &v1){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr ){
            v1.push_back(root->data);
            res.push_back(v1);
            return;
        }
        v1.push_back(root->data);
        pathToLeaf(root->left,res,v1);
        if(root->left) v1.pop_back();
        pathToLeaf(root->right,res,v1);
        if(root->right) v1.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        if(root==nullptr) return result;
        vector<int> v1;
        pathToLeaf(root,result,v1);
        return result;
    }
};

// Or we can also do this way by not passing the vector address

class Solution {
  public:
  
    void pathToLeaf(Node *root,vector<vector<int>> &res,vector<int> v1){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            v1.push_back(root->data);
            res.push_back(v1);
            return;
        }
        v1.push_back(root->data);
        pathToLeaf(root->left,res,v1);
        // if(root->left) v1.pop_back(); // We dont need to pop up because at every recurive step the vector is restores it its previous value
        pathToLeaf(root->right,res,v1);
        // if(root->right) v1.pop_back();
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        if(root==nullptr) return result;
        vector<int> v1;
        pathToLeaf(root,result,v1);
        return result;
    }
};

// Leetcode format

class Solution {
public:
    void path(TreeNode *root,vector<string> &res,string str){
        if(root==nullptr) return;
        if(!root->left && !root->right){
            str += (to_string(root->val) );
            res.push_back(str);
            return;
        }
        str += to_string(root->val) + "->";
        path(root->left,res,str);
        path(root->right,res,str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==nullptr) return result;
        string str="";
        path(root,result,str);
        return result;
    }
};


// Another Question
// Root to a particular node path

// for eg :-
// 1 2 3 4 5 N N N N 6 7

        //          1
        //      2       3
        //   4     5        
        //       6    7


void pathToLeaf(Node *root,vector<int> &v1,int x){
        if(root==nullptr) return false;
        v1.push_back(root->data);
        if(root->data == x) return true;
        bool leftPath = pathToLeaf(root->Left,v1);
        bool rightPath = pathToLeaf(root->right,v1);
        return leftPath || rightPath ;
        v1.pop_back();
        return false;
    }
  
    vector<vector<int>> Paths(Node* root) {
        if(root==nullptr) return result;
        vector<int> v1;
        pathToLeaf(root,v1);
        return result;
    }
        