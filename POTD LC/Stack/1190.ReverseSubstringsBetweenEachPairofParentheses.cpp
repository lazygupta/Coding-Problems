// Easy implementation
// Jyst like balanced parentheses


class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;
        for (auto ch:s){
            cout<<res.length()<<" ";
            if(ch == '(') st.push(res.length());
            else if(ch == ')'){
                int temp = st.top();
                st.pop();
                reverse(res.begin()+temp,res.end());
            }
            else{
                res.push_back(ch);
            }
        }
        return res;
    }
};