// Using two pointer approach we can do it

// First we have to sort it

// Just iterate from the both extremes
// If you find the sum just increment the left pointer
// And decrement the right pointer


// If at any time the sum<k you have to increase the left pointer

// Or else just decrease the right pointer

// T = O(NlogN) + O(N)
// S= O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int left =0, right = n-1;

        while(left<=right){
            int sum= nums[left]+ nums[right];

            if(sum==k){
                count++;
                left++;
                right--;
            }

            else if(sum<k) left++;

            else right--;
        }

        return count;
    }

};


// Same intuition as 1.Two_sum aka prefix sum

// Just store the remainder and its frequency
// Upon finding the rem in the map just decrement the value of remainder 
// And if the value of remainder becomes zero
// just remove the key from the map

// T=O(N) 
// S=O(N) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        int n = nums.size();

        int i=0,count =0;
        unordered_map<int,int> mpp;
        while(i<n){
            int rem = k-nums[i];
            if(mpp.find(rem) != mpp.end()){
                count++;
                mpp[rem]--;
                if(mpp[rem]==0)
                mpp.erase(rem);
                // nums[i]=0;
            }

            else mpp[nums[i]]++;

            i++;
        }

        return count;
    }

};