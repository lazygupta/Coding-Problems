// Problem Link - https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679


#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int check(int mid,int n,int m){
  ll ans=1;
  for(int i=0;i<n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans<m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low=1,high=m/n;
  while(low<=high){
    ll mid = low + (high-low)/2;
    int power = check(mid,n,m);
    if(power==0){
      return mid;
    }
    if(power==2){
      high = mid-1;
    }
    else if(power==1){
      low=mid+1;
    }
  }
  return -1;
}