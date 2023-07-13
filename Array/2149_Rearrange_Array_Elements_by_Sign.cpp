// Arranging the positive and negative integers of an Array alternatively

// Brute Force T.C -  O(N) + O(N) = O(2N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp;
        int neg[nums.size()],pos[nums.size()];
        int j=0,k=0;
        for(auto x:nums){
            if(x < 0) neg[j++]=x;
            else pos[k++]=x;
        }
        for(int i=0;i<nums.size()/2;i++){
            temp.push_back(pos[i]);
            temp.push_back(neg[i]);
        }
        return temp;
    }
};

// There is one more variety of this question in which the number of positive and Negative numberes are unequal.

// In that case the optimal solution is not there.
// Somehow we have to jump over the brute force solution

// This questiomn is a falloff question where you have to jump over the Brute force solution from the optimal one.