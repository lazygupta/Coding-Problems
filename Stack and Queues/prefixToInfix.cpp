// Implement using stack
// just start traversing from right to left side of the string

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool isOperator(char ch){
        switch(ch){
            case '*':
            case '+':
            case '-':
            case '/':
            case '%':
            case '^':
                return true;
        }
        return false;
    }  
  
    string preToInfix(string s) {
        // Write your code here
        stack<string> st;
        int i=s.length()-1;
        while(i>=0){
            if(!isOperator(s[i])){
                string t="";
                t+=s[i];
                st.push(t);
                // st.push(string(1, s[i]));
            }
            if(isOperator(s[i])){
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                string temp = "(" + op1 + s[i] + op2 + ")";
                st.push(temp);
            }
            i--;
        }
        return st.top();
    }
};