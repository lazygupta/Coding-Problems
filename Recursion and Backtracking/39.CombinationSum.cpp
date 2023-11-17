// Make recursion tree
// Based on pick and not pick

// Same as Aditya vErma concept

// I will call this as Verma's concept in Strivers way

// T.C = O(2^t) x k

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int index,int target,vector<int> &bucket,vector<int> candidates,vector<vector<int>> &res){
        if(index==candidates.size()){
            if(target==0)
            res.push_back(bucket);
            return;
        }
        if(candidates[index]<=target){ // this condition is because if the element is greater than the desired target 
        // then its of no use bcuz it can never fulfill teh desired target=0
        bucket.push_back(candidates[index]);
        find(index,target-candidates[index],bucket,candidates,res);
        bucket.pop_back();
        }
        find(index+1,target,bucket,candidates,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>bucket;
        find(0,target,bucket,candidates,result);
        return result;
    }
};