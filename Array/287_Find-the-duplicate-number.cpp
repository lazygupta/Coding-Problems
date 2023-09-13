// The numbers in the array is in th erange [1-n] only.

// T.C = O(N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num]<0) return num;
            nums[num]= -nums[num];
        }
        return -1;
    }
};


// Same queston 217. Contains Duplicate
// The array has duplicate numbers

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(auto i:nums){
            hset.insert(i);
        }
        return (nums.size()!=hset.size());
    }
};