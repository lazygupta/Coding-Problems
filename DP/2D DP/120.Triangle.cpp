// Just like grid, Go to every down and digonal and store the minimum value
// Build DP for memoization

// T.C = O(N*N)
// S.C = O(N)dp space + O(N*N) stack space

class Solution {
public:

    int solve(int n,int row,int col,vector<vector<int>> &dp,vector<vector<int>> &triangle){
        if(row == n-1){
            return triangle[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int down = INT_MAX,diag = INT_MAX;
        if(row<n) down = solve(n,row+1,col,dp,triangle);
        if(col<triangle[n-1].size()) diag = solve(n,row+1,col+1,dp,triangle);
        return dp[row][col] = triangle[row][col] + min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = 0;
        int col = 0;
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(n,row,col,dp,triangle);

    }
};