// Create a Monotonic stack everytime
// Same concept as next Greater Element to be followed 

// Approach:-
// 1. Start from left to right
// 3. Check everytime the top_stack element is less than the curr_element, if yes then pop it till the condition is true
// 2. Use map store a element next greater element
// O(n) - TC
// O(n) - SC

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mpp.count(nums1[i])?mpp[nums1[i]]:-1;
        }
        return nums1;
    }
};

// Another approach where we start traversing form start to end

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums2[st.top()] <= nums2[i]){
                mpp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mpp.count(nums1[i])?mpp[nums1[i]]:-1;
        }
        return nums1;
    }
};

