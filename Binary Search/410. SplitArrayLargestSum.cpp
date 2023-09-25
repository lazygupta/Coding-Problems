// We have to split the array into k parts
// Find our the maximum sum
// And then find out the minimum of maximum


// arr[]=[1,2,3,4,5]
// k=2

// Ways to part it into two
// 1. [1,2] [3,4,5] = max(3,12) = 12
// 2. [1] [2,3,4,5] = max(1,14) = 14
// 3. [1,2,3] [4,5] = max(6,9)  = 9
// and many more

// Out of thse the subarrays [1,2,3] and [4,5] are having sum 6,9 
// Comparing it within, 9 is maximum and comparing it with others 9 is the minimum of all maximums 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int check ( vector<int> &nums, int required_sum){
        int count=1; long long sum=0;
        for(int i=0;i<nums.size();i++){//4
            if( sum + nums[i] <= required_sum ){
                sum += nums[i]; // 5
            }
            else {
                count++;//2
                sum = nums[i];//4
            }
        }
        return count;
    }


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());//4
        int high = accumulate (nums.begin(),nums.end(),0);
        int ans=INT_MAX;//9
        while(low<=high){
            int mid = (low + high ) /2; //6

            if( check(nums,mid) > k){
                low=mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return low;
    }
};