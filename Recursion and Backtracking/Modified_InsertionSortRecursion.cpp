// This is the modified quick or insertion sorting algorithm only to understand recursion

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insert(vector<int> &v,int temp){
        if(v.size()==0 || v[v.size()-1]<temp){
            v.push_back(temp);
            return;
        }
        int val = v[v.size()-1];
        v.pop_back();
        insert(v,temp);
        v.push_back(val);
        return;
    }

    void sort(vector<int> &nums){
        if(nums.size()==1){
            return;
        }
        int temp=nums[nums.size()-1];
        nums.pop_back();
        sortArray(nums);
        insert(nums,temp);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        sort(nums);
        return nums;
    }

};