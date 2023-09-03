// Brute force solution comes up witht he logic to search for the element
// which is always greater than its neighbours
// and then returning its index

// T.C = O(N)
// S.C = O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n=nums.size();
        if(nums[0]>nums[1]) return 0;
        else if(nums[n-1]>nums[n-2]) return n-1;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
            return i;
        }
        return 0;
    }
};

// Optimal Approach

// Think of Binary Search

// T.C = O(N)
// S.C = O(1)

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int n = nums.size();
        if (nums[0] > nums[1])
            return 0;
        else if (nums[n - 1] > nums[n - 2])
            return n - 1;
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            else if (nums[mid + 1] > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return 0;
    }
};

// If the array condituion is nums[i]==nums[i+1] or nums[i]==nums[i-1]
// then above code fails

// In that conditiona n additionala line of code is necessary

//Inside the while loop

// if(nums[mid] == nums[mid+1] || nums[mid] == nums[mid-1]){
//                 return 1;
//             }