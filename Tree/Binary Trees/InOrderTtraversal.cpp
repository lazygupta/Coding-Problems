// recursive Way

void inOrder(TreeNode *node,vector<vector<int>> &v){
        if(node == NULL){
            return;
        }
        inOrder(node->left,v);
        v[0].push_back(node->data);
        inOrder(node->right,v);
    }


// Iterative way using stack LIFO

// Jab tk null na mile:-
// Stack me node daalte jaao jo jo milta jaa raha
// Node ke extreme left me jaate raho

// Null milte hi:-
// pehle stack se top element nikaal ke store krna hai answer me
// Aur fir right chale jaana hai
// Kisi bhi samay agar stack khaali hua toh ruk jaana hai


class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        TreeNode *node = root;
        stack<TreeNode*> st;
        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};