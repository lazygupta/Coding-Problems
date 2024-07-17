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

// Revision 17 July My solution

class Solution {
public:

    void helper(vector<int>& candidates,int index,int target,int sum, vector<vector<int>> &bucket,vector<int> &op){
        if(sum == target){
            cout<<sum<<" ";
            cout<<target;
            cout<<endl;
            bucket.push_back(op);
            return;
        }
        if(index >= candidates.size() || sum>target) return;
        sum += candidates[index];
        op.push_back(candidates[index]);
        helper(candidates,index,target,sum,bucket,op);
        op.pop_back();
        helper(candidates,index+1,target,sum-candidates[index],bucket,op);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> op;
        helper(candidates,0,target,0,res,op);
        return res;
    }
};