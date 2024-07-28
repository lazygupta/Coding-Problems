// Think deeply its a simple recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(vector<int> bucket,vector<vector<int>> &res,int k,int start, int n){
        if(bucket.size()==k && n==0){
            res.push_back(bucket);
            return;
        }
        for(int i=start;i<10;i++){
            bucket.push_back(i);
            find(bucket,res,k,i+1,n-i);
            bucket.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> bucket;
        find(bucket,res,k,1,n);
        return res;
    }
};

// revision on 24 July 2024

class Solution {
public:

    void solve(int sum,int index,int k,int n,vector<int> &nums,vector<int> &bucket,vector<vector<int>> &res){
        if(bucket.size() == k && sum == n){
            res.push_back(bucket);
            return;
        }
        for(int i=index;i<nums.size();i++){
            sum += nums[i];
            bucket.push_back(nums[i]);
            solve(sum,i+1,k,n,nums,bucket,res);
            bucket.pop_back();
            sum -= nums[i];
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> bucket;
        solve(0,0,k,n,num,bucket,res);
        return res;
    }
};