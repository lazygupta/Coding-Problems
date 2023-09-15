#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(auto x:nums2){
            nums1.push_back(x);
        }

        sort(nums1.begin(),nums1.end())

        else return nums1[mid];
    }
};