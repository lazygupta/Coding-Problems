// T.C = O(N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num]<0) return num;
            nums[num]= -nums[num];
        }
        return -1;
    }
};