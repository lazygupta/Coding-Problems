// Lower bound is the smallest index in an array whose element is greater than equal to target value. 
// Using BS

#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> arr, int n, int x) {

	int low=0 , high = n-1 , mid = 0;
	int answer = n;

	while(low<=high){

		mid = low + (high - low)/2;

		if( arr[ mid ] >= x ){
			high = mid -1;
			answer = mid;
		}

		else low = mid + 1;
	}

	return answer;
}


// Or you can also do this problem by using lower boyund stl function

// lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin() // arr.begin is minus because lower bound returns an itearator


// Upper bound
// Upper bound is the smallest index in an array whose element is greater than target value.

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.

	int low =0 , high= n-1;

	int mid =0;
	
	int ans = n ;

	while(low<=high){

		mid = low + (high - low) /2 ;

		if(arr[mid]> x){
			ans = mid;
			high = mid-1;
		}

		else low = mid+1;
	}

	return ans;
}

// Stl Function - 
// ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin();