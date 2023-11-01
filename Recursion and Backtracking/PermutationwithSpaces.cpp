#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    void solve(vector<string> &result,string input,string output){
        if(input.length()==0){
            result.push_back(output);
            return;
        }
        string op1=output;
        string op2=output;
        op1.push_back(' ');
        op1.push_back(input[0]);
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(result,input,op1);
        solve(result,input,op2);
    }

    vector<string> permutation(string S){
        // Code Here
        vector<string> result;
        string output;
        output.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(result,S,output);
        return result;
    }
};