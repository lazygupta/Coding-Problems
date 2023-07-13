// Using Hashing

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int h[10000]={0},i,j=0;
    for(i=0;i<n;i++){
        h[nums[i]]++;
    }
    for(j=1;j<=n;j++){
        if(h[j]==0) return j;
    }
	return 0;
    }
};



// O(n)


class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return ((n*(n+1))/2)-sum;
    }
};


// O(n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int x1=0,x2=0;
    for(int i=0;i<n;i++){
        x1=x1^nums[i];
        x2=x2^(i+1);
    }
    // x2=x2^(n+1);
    return x1^x2;
    }
};