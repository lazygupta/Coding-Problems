// Same as Q39 but the change was that we gave to consider only unique combination, we cant use same element multiple times

// T.C = O(2^t) * k logn
// S.C = k * X (Extra set data structure)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void find(int index,int target,vector<int> &bucket,vector<int> candidates,set<vector<int>> &res){
        
        if(index==candidates.size()){
            if(target==0)
            res.insert(bucket);
            return;
        }
       
        if(candidates[index]<=target){
            bucket.push_back(candidates[index]);
            find(index+1,target-candidates[index],bucket,candidates,res);
            bucket.pop_back();
        }
        find(index+1,target,bucket,candidates,res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> bucket;
        sort(candidates.begin(),candidates.end());
        find(0,target,bucket,candidates,res);
        vector<vector<int>> vec(res.begin(),res.end());
        return vec;
    }
};


// Memory Limit exceeds in above solution

// Without using any data structure

class Solution {
public:

    void find(int index,int target,vector<int> &bucket,vector<int> candidates,vector<vector<int>> &res){
        
        if(target==0){
            res.push_back(bucket);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            bucket.push_back(candidates[i]);
            find(i+1,target-candidates[i],bucket,candidates,res);
            bucket.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> bucket;
        sort(candidates.begin(),candidates.end());
        find(0,target,bucket,candidates,res);
        return res;
    }
};