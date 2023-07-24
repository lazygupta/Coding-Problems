// Stroing the past value in the hash table



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i =0;
        int count=0;
        sort(nums.begin(),nums.end());
        map<int , int> mpp;
        while(i<nums.size()){
            int rem = nums[i]-k;
            if(mpp.find(rem)!=mpp.end()){
                count=count+ mpp[rem];
            }
            mpp[nums[i]]++;
            i++;
        }
        return count;
    }
};

// HashTable without sorting


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i =0;
        int count=0;
        map<int , int> mpp;
        while(i<nums.size()){
            int rem = nums[i]-k;
            if(mpp.find(rem)!=mpp.end()){
                count=count+ mpp[rem];
            }

            if(mpp.find(nums[i]+k)!=mpp.end()){
                count=count+ mpp[nums[i]+k];
            }
            mpp[nums[i]]++;
            i++;
        }
        return count;
    }
};

// Anothe optimal approach we can replace our hash table with an array
// method 2: Counting sort
// simple and logical only.


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i =0;
        int ans=0;
        // sort(nums.begin(),nums.end());
        int counts[101]={0};
        for(auto num:nums){
            if (num > k) ans += counts[num - k]; // [1,2], k=1
	        if (num + k < 101) ans += counts[k + num]; // [2,1], k=1 
            counts[num]++;
        }
        return ans;
    }
};