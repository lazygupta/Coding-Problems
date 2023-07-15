// Binary Search

// So every time we are partitioning the array into two from mid

// T.C - O(log N)

// eg ., arr size = 32
// 32 -> 16-> 8 -> 4-> 2-> 1 = All together 6 steps . So log(base 2)32 gives near about 6

// For overflow condition
// mid = low + (high-low)/2


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int bs(vector<int>& nums,int low,int high, int target){
        if(low>high) return -1;

        int mid= (low+high ) / 2;
    
        if( nums[mid] == target) return mid;

        else if( nums[mid] > target) return bs( nums, low , mid - 1,target);

        else return bs(nums,mid +1 ,high,target);
    }


    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1, target);
    }
};

