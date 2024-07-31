// House Robber
// pick and not pick solution

// Think carefully

// TC = O(n)
// SC = O(n) + O(n)STACK SPACE 

class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if(n==0) return nums[0];
        if(n < 0) return 0; // this is just done to return the sum as 0 for rob variable so that we can consider only nums[n]
        if(dp[n] != -1) return dp[n];
        int rob = INT_MIN;
        rob = solve(nums,n-2,dp) + nums[n];
        int dontrob = solve(nums,n-1,dp);
        return dp[n] = max(rob,dontrob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, n - 1, dp);
    }
};

// Tabulation Approach
// As simple as all previous DP Problems

class Solution {
public:
// Tabulation Approach
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int rob = nums[i];
            if(i>1) rob += dp[i-2];
            int notrob = dp[i-1];
            dp[i] = max(rob,notrob);
        }
        return dp[n-1];
    }
};

// Now lets optimize the spacve using the classic fibonacci prev1 prev2 and curr_i pointer

class Solution {
public:
// Tabulation Approach - Space Optimisation
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1;i<nums.size();i++){
            int rob = nums[i];
            if(i>1) rob += prev2;
            int notrob = prev1;
            int curr_i = max(rob,notrob);
            prev2 = prev1;
            prev1 = curr_i;
        }
        return prev1;
    }
};