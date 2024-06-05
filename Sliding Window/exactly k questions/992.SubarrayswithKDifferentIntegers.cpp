// Asking for exactly k different integers subarrays
// Using the algorithm #Exactly K times = at most K times - at most K - 1 times
// Just count every subarrays which have less than k or equal to k integers
// If it exceeds trim down the window removing ith element
// Or else count each combination of subarrays of less than k or equal to k integers

//T.C = 2*(O(n) + O(n))
// S.C = o(n)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int countSubarrays(vector<int> &nums,int k){
        int i=0,j=0;
        int count=0;
        map<int,int> mpp;
        while(j<nums.size()){
            mpp[nums[j]]++;
            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            if(mpp.size() <= k){
                count += (j-i+1);
            }
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarrays(nums,k) - countSubarrays(nums,k-1);
    }
};
