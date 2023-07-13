// Brute Force
// T.C - O(N) + O(N)
// S.C - O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        for(auto x:nums){
            mpp[x]++;
        }
        int i=0;
        for (auto it = mpp.begin();it != mpp.end(); ++it)
        nums[i++]=it->first;
        return mpp.size();
    }
};


// Optimal Solution

// TC - O(N)
// SC - O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
        return i+1;
    }
};