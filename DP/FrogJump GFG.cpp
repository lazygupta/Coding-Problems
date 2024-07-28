// https://www.geeksforgeeks.org/problems/geek-jump

// Basic recursion technique
// It will give TLE


class Solution {
  public:
    
  int functionEntered = 0;
  int solve(vector<int>& height,int i) {
        functionEntered++;
        if(i==0) return 0;
        int oneStep =  solve(height,i-1) + abs(height[i-1]-height[i]);
        int twoStep = INT_MAX;
        if(i>1) twoStep = solve(height,i-2) + abs(height[i-2]-height[i]);
        return min(oneStep,twoStep);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        int res = solve(height,n-1);
        // cout<<functionEntered;
        return res;
    }
};

// Lets memoize it using dp

class Solution {
  public:
    
  int functionEntered = 0;
  int solve(vector<int>& height,int i,vector<int> &dp) {
        functionEntered++;
        if(i==0) return 0;
        if(dp[i] != -1) return dp[i];
        int oneStep =  solve(height,i-1,dp) + abs(height[i-1]-height[i]);
        int twoStep = INT_MAX;
        if(i>1) twoStep = solve(height,i-2,dp) + abs(height[i-2]-height[i]);
        return dp[i] = min(oneStep,twoStep);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n+1,-1);
        int res = solve(height,n-1,dp);
        // cout<<functionEntered;
        return res;
    }
};

// Lets discuss now Tabulation menthod

class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
        dp[0] = 0;
        for(int i=1;i<height.size();i++){
            int one = dp[i-1] + abs(height[i] - height[i-1]);
            int two = INT_MAX;
            if(i>1) two = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(one,two);
        }
        return dp[n-1];
    }
};

// Optimizing dp space in tabulation

class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        int prev2=0;
        int prev1=0;
        for(int i=1;i<height.size();i++){
            int one = prev1 + abs(height[i] - height[i-1]);
            int two = INT_MAX;
            if(i>1) two = prev2 + abs(height[i] - height[i-2]); 
            int curi = min(one,two);
            prev2 = prev1;
            prev1 = curi;
        }
        return prev1;
    }
};