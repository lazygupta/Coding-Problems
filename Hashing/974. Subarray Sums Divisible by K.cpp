// Read the question carefully and understand the logic

// Use of mathematical things here

// Suppose                                [2,3,5,4,5,3,4] and k = z
// Suppose any time we calc subarray sum s1~~~~~~~~~   = If s1%k = x
// And another subarray sum              s2~~~~~       = If s2%k = x
// Then (s1-s2)%k will also be x i.e., (4 + 5 ) % k == x


//Using the same logic we can store the remainder in the hashmap and check it 

 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int j=0,sum=0;
        int rem=0,count=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        while(j<nums.size()){
            sum+= nums[j];
            rem = sum%k;

            if(rem<0){// This condition is necessary as negative remainder will cause trouble
            // If you want reference go to youtube
                rem+=k;
            }

            if(mpp.find(rem) != mpp.end()){
                count = count + mpp[rem];
            }

            mpp[rem]++;
            
            j++;
        }
        return count;
    }
};