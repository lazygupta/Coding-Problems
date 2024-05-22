// Brute Force is very simple
// Iterate over every subarrays
// Find the sum which is equal to the target element
// Count the number of subarrays

// T.C = (N x N)
// S.C = O(1)

#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); // size of the given array.
    int cnt = 0; // Number of subarrays:

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}


// Optimal Approach
// Includes the concept of prefix sum

// The prefix sum tells us that the required subarrays are present if there is a required prefixsum

// We will add the current element i.e. arr[i] to the prefix sum.
// We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
// We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
// Then we will store the current prefix sum in the map increasing its occurrence by 1.


// T.C = O(N x 1) ---> best CAse ..... O(N x logN) -----> worst case if there is collission 

class Solution {
public:
    int subarraySum(vector<int>& a, int k){
        int sum=0,count=0;
        int rem=0;
        int i=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        while(i<a.size()){
            sum+=a[i];
            int rem = sum -k;
            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[sum]++;
            i++;
        }
        return count;
    }
};