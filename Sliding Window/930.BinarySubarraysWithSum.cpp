// Same as Subarrays whose sum equals k
// This is more optimal
// A new approach

// Just minus the Subarraysumslessthan(k) with subarrayssumlessthan(k-1)
// We will get sunarrays sums equals k

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int func(vector<int> &nums, int goal){
        if(goal<0) return 0;
        int sum=0,i=0,j=0;
        int count=0;
        while(j<nums.size()){
            sum += nums[j];
            while( sum > goal){
                sum -= nums[i];
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal) - func(nums,goal-1);
    }
};