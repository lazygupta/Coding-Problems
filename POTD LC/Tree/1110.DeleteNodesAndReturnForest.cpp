// VVI question
// Whenever you see tree question try to solve it using recursion

// Simply visit every node recursivelty check everytime the node values is to be deleted or not
// If the value is to be deleted then, store the left node value and right node value if they exist and delete the node

// Simply visit every node recursivelty check everytime the node values is to be deleted or not
// If the value is to be deleted then, store the left node value and right node value if they exist and delete the node

class Solution {
public:

    void helper(TreeNode* &node,unordered_set<int> st,vector<TreeNode*> &res){
        if(node!=nullptr){
            helper(node->left,st,res);
            helper(node->right,st,res);
            if(st.find(node->val)!=st.end()){
                if(node->left) res.push_back(node->left);
                if(node->right) res.push_back(node->right);
                node = nullptr;
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        vector<TreeNode*> res;
        for(auto it:to_delete){
            st.insert(it);
        }
        helper(root,st,res);
        if(root) res.push_back(root);
        return res;
    }
};