// Better Approach

// Using Hashing

// T.C = O ( N )
// S.C = O(N) + O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int , int> mpp;
        vector<int> v;
        int mini = (int)nums.size()/3 +1 ;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if (mpp[nums[i]] == mini) {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};

// Optimal Approach

// 