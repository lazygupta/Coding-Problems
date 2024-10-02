// We have to find single element in an Array
// In O(logN) time

// Understand carefully

// We check mid element is odd index or even index, If it odd index then we check its previous ele is same or not , If it save then its a even odd pair,
// Thus we are sure that we are in the left half and the ele lies on right half.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        else if (nums[n-1] != nums[n-2]) return nums[n-1];
        int low =1, high = n-2;
        int res=1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid] != nums[mid+1] && nums[mid]!=nums[mid-1]){// We are checking the middle element after every check
                return nums[mid];
            }
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))  { 
                low = mid+1;// We are checking for the left half of an array and then will remove it
// Because the element must be in the right half then
            }
            else high = mid-1; // Otherwise it would be in the left half so removinf 
        }
        return -1;
    }
};