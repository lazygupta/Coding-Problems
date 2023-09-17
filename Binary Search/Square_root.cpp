#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    // Write your code here.
    if(n==1) return 1;
    int low=1,high=n,res=1;
    while(low<=high){
        long long mid= low+(high-low)/2;
        if(mid*mid<=n){
            res=mid;
            low=mid+1;
        }
        else high = mid-1;
    }
    return res;
}