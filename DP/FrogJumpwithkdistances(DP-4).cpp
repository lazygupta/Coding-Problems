// Same as Frog jump
// Just there we were jumping for one step and two step everytime
// But here we have to jump 1 2 3 4 5 till k times
// So first intuition comes using for loop

class Solution {
  public:
  int solve(vector<int> &v,int n,int k,vector<int> &dp){
      if(n==0) return 0;
      if(dp[n] != -1) return dp[n];
      int minimum = INT_MAX;
      for(int i=1;i<=k;i++){
          int step;
          if(n-i>=0){
          step = solve(v,n-i,k,dp) + abs(v[n]-v[n-i]);
          minimum = min(step,minimum);
          }
      }
      return dp[n] = minimum;
  }
  
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,n-1,k,dp);
    }
};


// Using Tabulation method
// Bottom up approach
// Start filling dp[0] first and think about dp[1]

int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        int minimum = INT_MAX;
        for(int i = 1;i<arr.size();i++){
            int minimum = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int step = dp[i-j] + abs(arr[i] - arr[i-j]);
                    minimum = min(step,minimum);
                }
            }
            dp[i] = minimum;
        }
        
        return dp[n-1];
    }
};