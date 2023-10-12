// Using Stack we can do this problem   
// Primitive String

// Just push in stack the outermost parenthesis and store the index of outermost parenthesis

// T.C = O(N)
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        vector<int> li;
        if(s.length()==2) return "";
        for(int i=0;i<s.length();i++){
            if(st.size()==0) {
                li.push_back(i);
                st.push(s[i]);
            }
            else if(s[i] == '(' && st.top()==')'){
                st.pop();
                if(st.size()==0) li.push_back(i);
            }
            else if(s[i] == ')' && st.top()=='('){
                st.pop();
                if(st.size()==0) li.push_back(i);
            }
            else{
                st.push(s[i]);
            }
        }
        for(auto x:li){
            cout<<x<<" ";
        }
        cout<<endl;
        string Output="";
        for(int i=0;i<li.size();i+=2){
            int start =li[i]+1;
            int length = li[i+1]-1 - li[i];
            Output += s.substr(start , length );
        }
        return Output;
    }
};

// More optimized code but with little less time complexity
// And no Space complexity

// Primitive string will have equal number of opened and closed parenthesis.

// opened count the number of opened parenthesis.
// Add every char to the result,
// unless the first left parenthesis,
// and the last right parenthesis.

class Solution {
public:
    string removeOuterParentheses(string s) {
        string outputString="";
        int opened = 0;
        for(char c: s){
            if( c == '(' && opened++ > 0) outputString+=c;
            if( c == ')' && opened-- > 1) outputString+=c;
        }
        return outputString;
    }
};