
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int maxi=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]==0){
                k--;
            }
            while(k<0){
                if(nums[left]==0){
                    k++;
                }
                left++;
            }
            maxi = max (maxi , right-left +1);
        }
        return maxi;
    }
};