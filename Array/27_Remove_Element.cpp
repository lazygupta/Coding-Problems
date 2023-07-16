// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.


// Better Approach

// T.C - O(N) + O(N)
// S.C - O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;

        for(auto x: nums){
            if(x!=val)
            temp.push_back(x);
        }

        copy(temp.begin() ,temp.end(), nums.begin());

        return temp.size();
    }
};



// Optimal Approach - Using Two Pointer Approach
// T.C - O(N)
// S.C - O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,right=nums.size()-1;
        int cnt=0;
        while(left<=right){
            if(nums[left]==val){
                swap(nums[left], nums[right]);
                right--;
                cnt++;
            }
            else left++;
        }
        return nums.size() - cnt;
    }
};