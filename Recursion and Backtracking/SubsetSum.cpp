//Given a list arr of N integers, return sums of all subsets in it.

//https://www.codingninjas.com/studio/problems/subset-sum_3843086?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

// Make Recursion tree

#include<bits/stdc++.h>
using namespace std;

void find(int index,int sum,vector<int> num,vector<int> &res){
	if(index == num.size()){
		res.push_back(sum);
		return;
	}
	find(index+1,sum+num[index],num,res);
	find(index+1,sum,num,res);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int> result;
	find(0,0,num,result);
	sort(result.begin(),result.end());
	return result;
}