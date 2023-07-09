// The problem states that you are given an array of integers
// You have to find the longest sub array of sum k

// The problem can be done in O(n^2) in brute force solution


// I have solved this using Sliding Window Algorithm taking O(N) time complexity

// But the main problem is that my solution only works for the array containing only POSITIVE INTEGERS

#include<bits/stdc++.h>
using namespace std;

class Longest{
    public:

    int Longest_Subarray(vector<int> v,int k){
        int i=0,j=0;
        int sum=0,mx=0;
        while(j<v.size()){
            sum+=v[j];

            if(sum<k) j++;

            else if(sum==k){
                mx=max(mx,(j-i+1));
                j++;
            }

            else if (sum>k){
                while(sum>k){
                    sum = sum - v[i];
                    i++;
                    if(sum==k){
                        mx = max(mx,(j-i+1));
                    }
                }
                j++;
            }
        }
        return mx;
    }
};


int main(){
    int n=5;
    //17 15
    vector<int> arr={1,1,0,1,1};
    int k=2;
    Longest ob;
    int v1=ob.Longest_Subarray(arr,k);
    cout<<v1;
    return 0;
}


// 2nd Apporach 

// Using Hashing

//Hpwever this code with not work for array containing zeroes or negative number

int longestSubarrayWithSumK(vector<int> v, long long k) {
    long long sum=0;
    long long maxLen=0,len=0;
    map <long long,int> PreSumMap;
    for(long long i=0;i<v.size();i++){
        sum+=v[i];

        if(sum==k) maxLen=max(maxLen, i + 1);

        long long rem = sum-k;

        if(PreSumMap.find(rem) != PreSumMap.end()){
            len = i - PreSumMap[rem];
            maxLen = ( maxLen , len);
        }

        PreSumMap[sum] = i;
    }
    return maxLen;
}


