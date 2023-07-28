// My method was very simple
// I was just iterating through the array and storing the distinct prefix in the map and distinct suffix in map
// Then I was doing Substraction of counter variable left and right


// I dont know why my code was not running for the repeated arrays


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int j=0;
        map<int , int> mpp,mpp1;
        vector<int> v;
        int right=0,left=0;
        while(j<nums.size()){
            int r=j;
            while(r>=0){
                if(mpp.find(nums[r]) == mpp.end()){
                    left++;
                    
                }
                r--;
                mpp[nums[j]]++;
            }

            r=nums.size()-1;
            while(r>j){
                if(mpp1.find(nums[r])==mpp1.end()){
                    right++;
                }
                r--;
                mpp1[nums[j]]++;
            }
            v.push_back((left-right));

            mpp.clear();
            mpp1.clear();
            left=0;
            right=0;

            j++;

        }

        return v;
    }
};


// 2nd Method

// T =O(N*N)

// Just count the prefix and suffix same as the above and return prefix sixe - suffix size


class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int j=0;
        int n= nums.size();
        set<int> prefix,suffix;
        vector<int> v;
        while(j<n){
            int temp=j;
            while(temp>=0){
                prefix.insert(nums[temp]);
                temp--;
            }
            temp=n-1;
            while(temp>j){
                suffix.insert(nums[temp]);
                temp--;
            }
            v.push_back(prefix.size()-suffix.size());

            prefix.clear();
            suffix.clear();
            j++;

        }

        return v;
    }
};

// More optimal solution

// T= O(N) + O(N) = O(N) = S

// We are storing all the suffix beforehand
// Run a loop and keep the record for suffix and prefix
// If at anytime suffix freq becomes 0 , remove that suffix
// 

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int j=0;
        int n= nums.size();
        map<int,int> prefix,suffix;
        vector<int> v;
        for(auto cnt:nums)
        suffix[cnt]++;

        for(auto cnt: nums){
            prefix[cnt]++;
            suffix[cnt]--;
            if(suffix[cnt]==0) suffix.erase(cnt);
            v.push_back(prefix.size()-suffix.size());
        }

        return v;
    }
};