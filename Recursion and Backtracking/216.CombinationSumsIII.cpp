



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