// Same question as previous one 1011

// Binary Search as we know the rang of answers lies between maximum eleemnt and sum of the eleements
// Binary Search as we know the rang of answers lies between maximum eleemnt and sum of the eleements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sum(vector<int> &weights){
        int sum=0;
        for(auto i:weights){
            sum+=i;
        }
        return sum;
    }

    int maximum(vector<int> &v){
        int maximum=0;
        for(int i=0;i<v.size();i++){
            maximum = max (v[i], maximum);
        }
        return maximum;
    }

    int check(vector<int> &weights,int capacity){
        int load=0,days=1;
        for(int i=0;i<weights.size();i++){
            if((load + weights[i])> capacity){
                days+=1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = maximum(weights),high = sum(weights),ans=-1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(check(weights,mid) <= days){
                ans = mid;
                high = mid -1;
            }

            else low = mid +1;

        }

        return ans;
    }
};