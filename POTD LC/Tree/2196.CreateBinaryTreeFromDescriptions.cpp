// First store all the parent and child nodes in a hashmap only if its not there previously
// Then store every child element in a seperate hashmap

// Connect the left and right child to the parents


// Finally check which node is not there in the childnode Hashmap
// that is your final root node

// Return the root node


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root=nullptr;
        map<int,TreeNode*> node;
        map<int,bool> isChild;
        for(auto it:descriptions){
            if(node.find(it[0]) == node.end()){
                TreeNode *parent = new TreeNode(it[0]);
                node[it[0]] = parent;
            }
            if(node.find(it[1]) == node.end()){
                TreeNode *child = new TreeNode(it[1]);
                node[it[1]]= child;
            }
            if(it[2] == 1) node[it[0]]->left = node[it[1]];
            else node[it[0]]->right = node[it[1]];
            isChild[it[1]] = true;
        }
        for(auto it:descriptions){
            if(isChild.find(it[0]) == isChild.end()){
                root = node[it[0]];
            }
        }
        return root;
    }
};
