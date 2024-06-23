class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(s[0]==')' || s[0]=='}' || s[0]==']') return false;
        char ch;
        int i =0;
        stack<char> st;
        while(i<n){
            if(s[i] == '(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                ch = st.top();
                if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='[')){
                    st.pop();
                }
                else return false;
            }
            i++;
        }
        return st.empty();
    }
};