
// brute Force Approach
// Generate all the permutations
// Return the permutation just after the given array

// Better Approach
// Using C++ STL
//T.C = O(3N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        next_permutation(arr.begin(),arr.end());
        // cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    }
};

// The internal working of C++ STL next_permutation

// Optimal Approach
// Take an example 
// { 2 1 5 4 3 0 0}
// What will be the next permutation of the above array
// Choose prefix


// Choosing first 4 prefix ..... We can change only in {3 0 0}....

// As we know the next permutation will always be greter than the given array

// Now choosing first 3 prefix .... We can change only in {4 3 0 0}
// Now choosing first 2 prefix .... We can change only in {5 4 3 0 0}
//                               |
//                               |
//                               |
//                               |
//                               |
//      From last selection we can select largest number { 5 4 3 1 0 0 } , { 5 3 4 1 0 0} , {5 3 4 1 0 0} ......etc
// Now we have to select the minimum largest number greater than { 1 5 4 3 0 0 }

// Swapping the 1 with the smallest of largest digit
// So the largest number should be starting with the smallest of all the numbers -------> {3 5 4 1 0 0 }

// Now reversing the array after 3 , we would get the smallest of the largest number ---> { 0 0 1 4 5 }

//Result ------> { 2 3 0 0 1 4 5}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind = -1;
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i = n-1 ; i>ind ; i--){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};

