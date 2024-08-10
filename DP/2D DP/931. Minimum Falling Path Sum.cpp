// The recursion solution will give TLE

// Memoizing it using DP

// T.C = O(N*N)
// S.C = O(N) + O(N*M)

class Solution {
public:

    int solve(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>& dp){
        if(i==0 && j<n && j>=0){
            return matrix[i][j];
        }
        if(j>=n || j<0) return 1e7;
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int up = solve(matrix,i-1,j,n,dp);
        int left = solve(matrix,i-1,j-1,n,dp);
        int right = solve(matrix,i-1,j+1,n,dp);
        return dp[i][j] = matrix[i][j] + min(up,min(left,right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows;
        vector<vector<int>> dp(rows+1,vector<int> (cols+1,INT_MAX));
        int res = INT_MAX;
        for(int j=0;j<cols;j++){
            res = min(res,solve(matrix,rows-1,j,n,dp));
        }
        return res;
    }
};

