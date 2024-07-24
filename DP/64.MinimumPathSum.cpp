class Solution {
public:

    int solve(vector<vector<int>>& grid,int row,int col,int i,int j,vector<vector<int>>& dp){
        if(i>=row || j>=col) return INT_MAX;
        if(i== row-1 && j == col -1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = grid[i][j] + min(solve(grid,row,col,i+1,j,dp),solve(grid,row,col,i,j+1,dp));
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        return solve(grid,row,col,0,0,dp);
    }
};