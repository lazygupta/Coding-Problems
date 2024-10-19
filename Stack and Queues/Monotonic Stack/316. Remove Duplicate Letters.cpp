// 

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26,0);
        for(int i=0;i<s.length();i++){
            lastIndex[s[i]-'a'] = i;
        } 
        stack<char> st;
        vector<bool> seen(26,false);
        for(int i=0;i<s.length();i++){
            int ch = s[i] - 'a';
            if(seen[ch]) continue;
            while(!st.empty() && st.top()>s[i] && i<lastIndex[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[ch] = true;
        }
        string str ="";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};