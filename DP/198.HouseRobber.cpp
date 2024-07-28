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