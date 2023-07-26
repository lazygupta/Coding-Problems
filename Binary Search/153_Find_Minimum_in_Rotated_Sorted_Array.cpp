// We have to find the minimum element in the sorted array

// Since this is a sorted array , We must try Binary Search

// We have to search which part of the array is sorted

// { 7, 8 , 1 ,2 , 3 ,4 , 5, 6}

// In the above example right half is sorted 
// So we should store minimum value at low index and the remove the right half of the array imaginary

// {7, 8 ,1 }
// Now the left half is sorted so minimum again updates to array [min] and the right half is removed

// { 1}
// The right or left both half is sorted store the minimum and remove

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0 ,mid =0, high = nums.size()-1;
        int minimum = INT_MAX;
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[low]<=nums[mid]){
                minimum = min ( minimum , nums[low]);
                low = mid +1;
            }

            else {
                minimum = min ( minimum , nums[mid]);
                high = mid -1;
            }
        }

        return minimum;

    }
};

// We can be ask with how many times the array has been rotated
//In that case our answer will be index of minimum array

int findKRotation(vector<int> &arr){
    // Write your code here.    
    int low = 0, high = arr.size()-1;
    int minimum = 1e9;int index;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[low]<=arr[mid]){
            // minimum = min (minimum , nums[low]);
            if(arr[low] < minimum){
                minimum = arr[low];
                index = low;
            }
            low = mid +1;
        }

        else {
            // minimum = min (minimum , nums[mid]);
            if(arr[mid] < minimum){
                minimum = arr[mid];
                index = mid;
            }
            high = mid -1;
        }

    }

    return index;
}