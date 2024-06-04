// Same as Subarrays with sum excatly k
// #Exactly K times = at most K times - at most K - 1 times


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxSubarray(vector<int> &nums,int k){
        int i=0,j=0;
        int oddNumbers = 0,count = 0;
        while(j<nums.size()){
            k -= nums[j] % 2;
            while(k<0){
                k += nums[i]%2;
                i++;
            }
            count += (j-i+1);
            j++;
        }
        cout<<count<<endl;
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return maxSubarray(nums,k) - maxSubarray(nums,k-1);
    }
};