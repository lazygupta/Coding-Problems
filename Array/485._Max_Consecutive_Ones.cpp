//This problenm can be solved same as 268 Missing Number

// Using XOR fucntion its very easy to solve duplicate / Missing / Repeating Twice Questions

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else count=0;
            mx=max(mx,count);
        }
        return mx;
    }
};

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.