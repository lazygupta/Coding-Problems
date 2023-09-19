

// 1st method


class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        int size = max(nums1.size(), nums2.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
            {
              if (find(v.begin(), v.end(), nums1[i]) == v.end())
              v.push_back(nums1[i]);
            }
        }
        return v;
    }
};



// 2nd method

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