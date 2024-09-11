#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}

    string postToInfix(string s) {
        // Write your code here
        stack<string> st;
        int i = 0;
        int n = s.length();
        while(s[i] != '\0'){
            if(isOperand(s[i])){
                string op(1, s[i]);
                st.push(op);
            }
            else {
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                st.push('(' + c2 + s[i] + c1 + ')');
            }
            i++;
        }
        return st.top();
    }
};