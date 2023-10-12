#include<bits/stdc++.h>
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int> &a){
	// Write your code here.
	int sum=0,count=0;
        int rem=0;
        int i=0;
		int k=0;
		int maxi=0;
        unordered_map<int,int> mpp;
        mpp[0]=1;
        while(i<a.size()){
            sum+=a[i];
			if(sum==0 ) maxi = i+1;
            else if(mpp.find(sum) != mpp.end()){
				maxi = max ( maxi , i - mpp[sum]);
            }
            else mpp[sum] = i;
            i++;
        }
        return maxi;
}