// Very Simple 

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto it:logs){
            if(it != "../" && it!="./"){
                st.push(it);
            }
            else if(it=="./") continue;
            else{
                if(st.size()>0) st.pop();
            }
        }
        return st.size();
    }
};