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

// revision 15 July

class Solution {
public:

    void generate(int open, int close , int n, vector<string> &res, string str){
        if(str.length() == n*2){
            res.push_back(str);
            return;
        }
        if(open < n){
            generate(open+1,close,n,res,str+'(');
        }
        if(close < open){
            generate(open,close+1,n,res,str+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0,0,n,res,"");
        return res;
    }
};