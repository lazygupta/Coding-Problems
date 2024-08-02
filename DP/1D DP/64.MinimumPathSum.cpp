// Memoization Approach
// Traverse accross boundary
// Suppose u r starting from last cell
// up up up up up up up .............
// As up exhaust or out of boundary return INT_MAX because we dont have to consider the cell value which is out of boundary
// we will move left left left left left.....
// Always fill the dp array with minimum cell value

// T.C =  O(N*M)
// S.C =  O((M-1)+(N-1)) + O(N*M)

class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + 
                            min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        return solve(row-1,col-1,grid,dp);
    }
};

// Tabulation Approach

// Bottom Up approach
// Reducing the Recursion Stack Space

// T.C =  O(N*M)
// S.C =  O(N*M)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Tabulation
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }

                else{
                    int right = INT_MAX, down = INT_MAX;
                    if(j>0) right = dp[i][j-1];
                    if(i>0) down = dp[i-1][j];
                    dp[i][j] = grid[i][j] + min(right,down);
                }
            }
        }
        return dp[row-1][col-1];
    }
};