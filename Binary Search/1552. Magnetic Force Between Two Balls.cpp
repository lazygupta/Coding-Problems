// We are given with m number of balls
// Put the balls into the baksets such that minimum magnetic foce between any two balls is maximum among all

// e,g arr = {1,2,3,4,7}
// m = 3

// There are 3 baskets try inserting baskest at distances starting from 1 till maximum of distance
// At 1 ----> 1-2-3 -----> Minimum dist = 1
// At 2 ----> 1-3-7 -----> Minimum dist = 2
// At 3 ----> 1-4-7 -----> Minimum dist = 3
// From above the maximum of miniomum distance = 3
// 3 is the answer

// As we know our answer lies between 1 and maximum of element
// We can aplly Binary Search

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool check(vector<int> &position,int dist,int m){
        int n= position.size();
        int count=1,basket_position=position[0];
        for(int i=1;i<n;i++){
            if( position[i] - basket_position >= dist){
                count++;
                basket_position=position[i];
            }
        }
        if(count >= m) return true;
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n= position.size();
        int low=1;
        int high = position[n-1];//7
        while(low<=high){
            int mid = low+(high-low)/2;//4//2//3//3
            if(check(position,mid,m)== true){
                low=mid+1;
            }
            else high = mid-1;
        }
        return low-1;
    }
};