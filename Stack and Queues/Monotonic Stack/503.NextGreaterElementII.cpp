// Same as 496.Next greater element
// Just a small change that this is a circular arrays
// Traversing from right to left

// Juat double the size fo the array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()) result[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        return result;
    }
};

// Another method
// Traversing from left to right aka start to end

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n,-1);
        for(int i=0;i<2*n-1;i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                result[st.top()]= nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i%n);
        }
        return result;
    }
};