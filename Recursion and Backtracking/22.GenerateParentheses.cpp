// Think of recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void result(int open,int close,string output,vector<string> &v){
        if(open==0 && close ==0){
            v.push_back(output);
            return;
        }
        if(open>0){
            string op1=output;
            op1.push_back('(');
            result(open-1,close,op1,v);
        }
        if(close>open){
            string op2=output;
            op2.push_back(')');
            result(open,close-1,op2,v);
        }

    }

    vector<string> generateParenthesis(int n) {
       int open =n, close =n;
       string output="";
       vector<string> v;
       result(open,close,output,v); 
       return v;
    }
};