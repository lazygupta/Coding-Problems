// Recursive way

void postOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        postOrder(node->left,v);
        postOrder(node->right,v);
        v[2].push_back(node->data);
}


// Iterative way using two stack

// Stack 1 me pehle root daalna hai

// Jab tk stack 1 ka size 0 na ho jaaye:-
// Stack 2 me stack 1 ka top element daalna hai
// Stack 1 se fir pop out krna hai
// Agar stack 1 me left and right hai toh stor ekr lena hai stack 1 me
// AUr fir se same prc0ess repeat krna hai

// The 2nd stack will be having our answer

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr) return v;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st2.push(root);
            st1.pop();
            if(root->left != nullptr) st1.push(root->left);
            if(root->right != nullptr) st1.push(root->right);
        }
        while(!st2.empty()){
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
    }
};