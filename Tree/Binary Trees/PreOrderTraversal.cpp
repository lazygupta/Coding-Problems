// Recursive Method


void preOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        v[1].push_back(node->data);
        preOrder(node->left,v);
        preOrder(node->right,v);
    }



// Iterative Method

class Solution {
public:
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) return v;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            v.push_back(root->val);
            if(root->right != nullptr) st.push(root->right);
            if(root->left != nullptr) st.push(root->left);
        }
        return v;
    }
};

