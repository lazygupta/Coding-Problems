class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        for(auto& it: s){
            if(it == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(it);
            } else {
                st.push(it);
            }
        }
        return st.size();
    }
};

// Space optimized

class Solution {
public:
    int minAddToMakeValid(string s) {
        int right = 0,left = 0;
        for(auto it: s){
            if(it == '('){
                right++;
            }
            else if(right>0){
                right--;
            } else {
                left++;
            }
        }
        return right+left;
    }
};
