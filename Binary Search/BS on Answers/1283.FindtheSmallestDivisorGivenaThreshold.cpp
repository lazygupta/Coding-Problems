// Same question as 875 

// Binary Search

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximum(vector<int> &v){
        int maximum=0;
        for(int i=0;i<v.size();i++){
            maximum = max (v[i], maximum);
        }
        return maximum;
    }

    bool SumOfDivision(vector<int> &v,int divisor,int threshold){
        int sum=0;
        for(auto x:v){
            sum += ceil(double(x)/double(divisor));
        }
        if(sum<=threshold){
            return true;
        }
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1,high=maximum(nums);
        int ans=-1;
        while(low<=high){
            int mid = low +(high - low)/2;

            if(SumOfDivision(nums,mid,threshold)){
                ans = mid;
                high = mid-1;
            }

            else {
                low = mid+1;
            }

        }
        return ans;
    }
};