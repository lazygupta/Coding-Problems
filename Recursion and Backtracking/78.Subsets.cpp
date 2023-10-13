// Geberate all the subsets of a string

// This problem can be solves by using power set algorithm
// 1st method - Power set



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
        find(index+1,v,nums,temp,n);
        v.pop_back();
        find(index+1,v,nums,temp,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        vector<int> v1;
        find(0,v1,nums,v,n);
        return v;
    }
};