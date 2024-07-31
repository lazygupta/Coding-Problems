// So this question is the basic building for 2d dp concepts

// This question can be done with the greedy aproach but it will fail

// So we can try Recursion

// Step 1:- Explore every index
// Step 2:- DO all stuffs on that index
// Step 3:- Find max

// T.C = O(n*3*n)*m
// S.C = O(n)(Recursion stack) + O(m)(Dp spaace)

class Solution {
  public:
  
    int solve(vector<vector<int>> &arr,int n,int index){
        if(n==0){
            int maxi = INT_MIN;
            for(int i=0;i<3;i++){
                if(i!=index) maxi = max(maxi,arr[0][i]);
            }
            return maxi;
        }
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=index){
                int points = arr[n][i] + solve(arr,n-1,i);
                maxi = max(maxi,points);
            }
        }
        return maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return solve(arr,n-1,3);
    }
};

// Now we will try to memoize it using dp
// T.C = O(n*3)*m
// S.C = O(n)(Recursion stack) + O(m)(Dp spaace)


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int solve(vector<vector<int>> &arr,int n,int index,vector<vector<int>> &dp){
        if(n==0){
            int i;
            int maxi = INT_MIN;
            for(i=0;i<3;i++){
                if(i!=index) maxi = max(maxi,arr[0][i]);
            }
            return maxi;
        }
        if(dp[n][index] != -1) return dp[n][index];
        int maxi = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=index){
                int points = arr[n][i] + solve(arr,n-1,i,dp);
                maxi = max(maxi,points);
            }
        }
        return dp[n][index] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(arr,n-1,3,dp);
    }
};

// Try Tabulation method

// T.C = O(n*3*n)*m
// S.C = O(m)(Dp spaace)

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0] = max(arr[0][1],arr[0][2]);
        dp[0][1] = max(arr[0][2],arr[0][0]);
        dp[0][2] = max(arr[0][0],arr[0][1]);
        dp[0][3] = max({arr[0][1],arr[0][2],arr[0][0]});
        for(int day=1;day<n;day++){
            for(int lastidx=0;lastidx<4;lastidx++){
                dp[day][lastidx] = 0;
                for(int task=0;task<3;task++){
                    if(task!=lastidx){
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][lastidx] = max(dp[day][lastidx],points);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};