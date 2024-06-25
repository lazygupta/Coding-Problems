// Brute Approach

vector<int> moveZeros(int n, vector<int> a) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    int nz = temp.size();

    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}


// Optimal Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
        }
    }
};