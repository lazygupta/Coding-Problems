// Check that right node data + left node data == parent data

// Using recursion we can do this easily

// Just implement a base case for root==null and root being a leaf node

#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    public:
    int isSumProperty(Node *root)
    {
        
        int sum =0;
        if(!root || (!root->left && !root->right)) return 1;
        else{
            if(root->left){
                sum  += root->left->data;
            }
            if(root->right){
                sum += root->right->data;
            }
            
            bool check = isSumProperty(root->left) && isSumProperty(root->right);
            
            return (root->data == sum) && check;
        }
        
        return 0;
        
    }
};