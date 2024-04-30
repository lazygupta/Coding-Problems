// Sliding window algorithm
// If your number of zeroes exceeds k, then move window to the element which satisfies the condiiton of no_of_zeroes==k
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int no_of_zeroes = 0;
        int i=0,j=0;
        int maxLength=0;
        while(j<nums.size()){
            if(nums[j] == 0){
                no_of_zeroes++;
            }
            while(no_of_zeroes>k){
                if(nums[i] == 0){
                    no_of_zeroes--;
                }
                i++;
            }
            int len = j-i+1;
            maxLength = max ( maxLength, len);
            j++;
        }
        return maxLength;
    }
};
};