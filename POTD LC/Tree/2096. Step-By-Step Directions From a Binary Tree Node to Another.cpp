// Store the path of each starting node in a string
// Store the path of each endingNode in a sepearte string

//Note that since we are using backtracking so gthe path will be stored in reverse direction



class Solution {
public:

    bool helper(TreeNode* root,int nodeVal,string &str){
        if(root==nullptr) return false;
        if(root->val == nodeVal){
            return true;
        }
        if(root->left && helper(root->left,nodeVal,str)){
            str.push_back('L');
        }
        else if(root->right && helper(root->right,nodeVal,str)){
            str.push_back('R');
        }
        return !str.empty();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startNodePath = "",endNodePath = "";
        helper(root,startValue,startNodePath);
        helper(root,destValue,endNodePath);
        cout<<startNodePath<<" "<<endNodePath<<endl;
        while(startNodePath.length() && endNodePath.length() && startNodePath.back()==endNodePath.back()){
            startNodePath.pop_back();
            endNodePath.pop_back();
        }
        string str(startNodePath.length() , 'U');
        string str2(rbegin(endNodePath), rend(endNodePath));
        return str+str2;
    }
};