// Just Like prefix Sum
// Just store the modulus value
// Because upon adding the meodulus value to the number it will be divisible by k


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int j=0,sum=0;
        map<int,int> mpp;
        mpp[0]=-1;
        if(nums.size()<2)
            return false;
        while(j<nums.size()){
            sum += nums[j];
            int req = sum % k;

            if(mpp.find(req) != mpp.end()){
                int pre = mpp[req];
                if(j-pre >= 2)
                return true;
            }

            else mpp[req]=j;
            j++;
            
        }
        return false;
    }
};