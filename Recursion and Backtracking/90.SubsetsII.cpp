// This question is different from his parent question 78. Subsets

// The input are having numbers which icntain dupliactes too

// T.C = O(2^n) * k log n
// S.C = O(2n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> input,vector<int> output,set<vector<int>> &v){
        if(input.size()==0){
            v.insert(output);
            return;
        }
        vector<int> op1;
        vector<int> op2;
        op1=output;op2=output; 
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(input,op1,v);
        solve(input,op2,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        solve(nums,output,v);
        vector<vector<int>> res{v.begin(),v.end()};
        return res;
    }
};

// Now try to avoid the use of sets

// Make recursion tree call the function multiple times at every iteration we get the answer

class Solution {
public:
    void solve(int index,vector<int> input,vector<int> bucket,vector<vector<int>> &res){
        res.push_back(bucket);
        for(int i=index;i<input.size();i++){
            if(i>index && input[i]==input[i-1]) continue;
            bucket.push_back(input[i]);
            solve(i+1,input,bucket,res);
            bucket.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> output;
        vector<vector<int>> v;
        solve(0,nums,output,v);
        return v;
    }
};