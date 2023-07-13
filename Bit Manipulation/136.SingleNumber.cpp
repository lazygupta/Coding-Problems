//Finding one single number in twice repeating integers

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0,i=0;
        for(int i=0;i<nums.size();i++){
            x1=x1^nums[i];
        }
        return x1;
    }
};


// Input: nums = [2,2,1]
// Output: 1