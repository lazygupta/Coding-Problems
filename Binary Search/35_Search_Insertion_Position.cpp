// You are given with an array and you have to insert a element in it in the sorted manner position

// You just have to retutn the index position

// So upon thinking we can conclude that the number has to be inserted in its lower bound position

#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.

	int answer = 0;
	answer = lower_bound(arr.begin(),arr.end(),m) - arr.begin();

	return answer;
}