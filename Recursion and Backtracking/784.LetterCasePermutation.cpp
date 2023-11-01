// Same as Permutation withh spaces
// Draw Recursive tree and then write the code 
// call the recursive function two times
// One for Output1 of recursive tree
// Second for output2 of recursive tree

// I/P = {ab}
// O/P = {ab} {aB} {Ab} {AB}

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string> &result,string input,string output){
        if(input.length()==0){
            result.push_back(output);
            return;
        }
        string output1=output;
        string output2=output;
        output1.push_back(input[0]);
        output2.push_back(isupper(input[0])?tolower(input[0]):toupper(input[0]));
        input.erase(input.begin()+0);
        solve(result,input,output1);
        solve(result,input,output2);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string output="";
        solve(result,s,output);
        return result;
    }
};


// Variety 2

// I/P = ["a1b"]
// O/P = ["ABC","ABc","AbC","Abc","aBC","aBc","abC","abc"]


// Our above code will not work for above code
// We have to surpass the non-alphabet symbols

class Solution {
public:
    void solve(vector<string> &result,string input,string output){
        if(input.length()==0){
            result.push_back(output);
            return;
        }
        if(isdigit(input[0])){
            output+=input[0];
            input.erase(input.begin()+0);
            solve(result,input,output);
        }
        else{
        string output1=output;
        string output2=output;
        output1.push_back(input[0]);
        output2.push_back(isupper(input[0])?tolower(input[0]):toupper(input[0]));
        input.erase(input.begin()+0);
        solve(result,input,output1);
        solve(result,input,output2);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string output="";
        solve(result,s,output);
        return result;
    }
};