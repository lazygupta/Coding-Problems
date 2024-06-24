// Simple Implementation through stack
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        int n = s.length();
        int i=0;
        string output="";
        unordered_map<char,int> mpp;
        mpp['+'] = 1; // Storing the priority of the arithmetic operators
        mpp['-'] = 1;
        mpp['*'] = 2;
        mpp['/'] = 2;
        mpp['^'] = 3;
        while(i<n){
            if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)){
                output.push_back(s[i]);
            }
            else if(st.empty() || s[i]=='(' ){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty()){
                    if(st.top()=='(') {
                        st.pop();
                        break;
                    }
                    output.push_back(st.top());
                    st.pop();
                }
            }
            else{
                while(!st.empty()){
                    if(st.top() == '('){
                        break;
                    } 
                    if(mpp[st.top()] >= mpp[s[i]]){
                        output.push_back(st.top());
                        st.pop();
                    }
                    else break;
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
          output.push_back(st.top());
          st.pop();
        } 
        return output;
    }
};

// Or to decrease the space used we can not use map

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// We can use above function to get priority of the arithmetic operators