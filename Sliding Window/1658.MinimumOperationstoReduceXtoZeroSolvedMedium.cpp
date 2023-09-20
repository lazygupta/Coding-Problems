// Very good question

// The number of elements removed equals n minus the number of elements that aren't removed.

// Therefore, to find the minimum number of elements to remove, we can find the maximum number of elements to not remove!

// We have to find the sum of maximum length to be equalt to (sum-x)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,j=0;
        //1 1 4 2 3
        int sum=0;int maxi=-1;
        for(auto x:nums){
            sum+=x;//11
        }
        if(sum<x) return -1;
        int curr_sum=0;
        for(int j=0;j<nums.size();j++){
            curr_sum+=nums[j];
            if(curr_sum > (sum-x) ){
                while(curr_sum > (sum-x)){
                    curr_sum -= nums[i++];
                    if(curr_sum==(sum-x)){
                        maxi=max(maxi,j-i+1);
                    }
                }
            }
            if(curr_sum == (sum-x)) {
                maxi=max(maxi,j-i+1);
            }
        }
        return maxi==-1 ? -1 : nums.size()-maxi;
    }
};

// Easy method
// But i understood above one so

// public int minOperations(int[] nums, int x) {
// 	int sum = 0;
// 	for (int num: nums) sum += num;

// 	int maxLength = -1, currSum = 0;
// 	for (int l=0, r=0; r<nums.length; r++) {
// 		currSum += nums[r];
// 		while (l <= r && currSum > sum - x) currSum -= nums[l++];
// 		if (currSum == sum - x) maxLength = Math.max(maxLength, r-l+1);
// 	}

// 	return maxLength == -1 ? -1 : nums.length - maxLength;
// }