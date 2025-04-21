// Brute solution

// O(n+n)

class Solution {
public:
    bool check(vector<int>& nums) {
        int index = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                index = i+1;
                break;
            }
        }
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if((nums[(i+index) % n]) > nums[(i+index+1) % n]){
                return false;
            }
        }
        return true;
    }
};

// Optimal


// Find how many times, the array is breaking the ascending order.
// If it is breaking just once or not even once then it is sorted so return true, otherwise false.
// If the next element is smaller, then it should be only once
// Because if that will  be more than one then it will not be a sorted array

// Hints:- 
// See if the number is increasing it should be increasing the moment it starts decreasing it should decrease always


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int count=0;
            for(int i = 0; i< nums.size() -1 ;i++){
              if(nums[i]>nums[i+1]){
                count++;
              }
            }
            if(nums[nums.size()-1] > nums[0]) count++; // This is done to check for these cases [2,1,3,4], where the condition satisfies but how come when the arrays start decreasing it increase 
            cout<<count;
            return count<=1;
        }
    };

// Better solution
// Ignore the extra check do it in runtime loop

class Solution {
    public:
        bool check(vector<int>& nums) {
            // checking the next ele is greater always or not
            int count=0;
            for(int i = 0; i< nums.size() ;i++){
              if(nums[i]>nums[(i+1)%nums.size()]){ // nums[n-1]> nums[n-1+1%n] => nums[n-1]> nums[0] 
                count++;
              }
            }
            cout<<count;
            return count<=1;
        }
    };