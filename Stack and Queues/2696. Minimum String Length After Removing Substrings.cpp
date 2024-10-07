// Push into the stack
// On every next iteration check the topp of the stack is making some pattern with the current s[i]
// If that is the case pop the stack
// else push into the stack evey ele

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i =0;i<s.length();i++){
            if(s[i] == 'B' && st.size() && st.top() == 'A'){
                st.pop();
            }
            else if(s[i] == 'D' && st.size() && st.top() == 'C'){
                st.pop();
            } 
            else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};