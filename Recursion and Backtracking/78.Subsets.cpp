// Dont confuse this question iwth SubsetII problem
// The inputs contains no duplicates thats why answers are unique


// Generate all the subsets of a string

// This problem can be solves by using power set algorithm
// 1st method - Power set

//   0 1 2
// 0 0 0 0 = "" // 001 & 001
// 1 0 0 1 = "c"
// 2 0 1 0 = "b"
// 3 0 1 1 = "bc"
// 4 1 0 0 = "a"
// 5 1 0 1 = "ac"
// 6 1 1 0 = "ab"
// 7 1 1 1 = "abc"

class Solution {
public:
// Power Set
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=1<<n;//int p=pow(2,n);
        vector<vector<int>> result(p);
        for(int i=0;i<p;i++){
            for(int j=0;j<n;j++){
                if((i >> j) & 1){
                    result[i].push_back(nums[j]);
                }
            }
        }
        return result;
    }
};

//2nd method

//Recursive way of generating all the subsets of a string

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void find(int index,vector<int> v,vector<int> nums,vector<vector<int>> &temp,int n){
        if(index>=n){
            temp.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        find(index+1,v,nums,temp,n); //----> Take
        v.pop_back();
        find(index+1,v,nums,temp,n); // -----> Not Take
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        vector<int> v1;
        find(0,v1,nums,v,n);
        return v;
    }
};

// Recursion 3rd way

class Solution {
public:

    void solve(vector<int> input,vector<int> output,vector<vector<int>> &v){
        if(input.size()==0){
            v.push_back(output);
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> v;
        solve(nums,output,v);
        return v;
    }
};