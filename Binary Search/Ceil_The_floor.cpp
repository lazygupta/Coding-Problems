


#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	int low =0 , high = n-1;
	int mid =0 , ans =-1,ans1=-1;

	sort(arr,arr+n);

	while(low<=high){
		mid = low + (high - low) / 2;

		if(arr[mid] <= x){
			ans = arr[mid];
			low = mid+ 1;
		}

		else high = mid -1 ;
	}
	low =0 , high = n-1;

	while(low<=high){
		mid = low + (high - low) / 2;

		if(arr[mid] >= x){
			ans1 = arr[mid];
			high = mid - 1;
		}

		else low = mid + 1 ;
	}

	return make_pair(ans,ans1);
}
