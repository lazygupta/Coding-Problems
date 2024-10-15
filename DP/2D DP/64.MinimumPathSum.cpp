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

    int func(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up = func(grid,i-1,j,dp);
        int left = func(grid,i,j-1,dp);
        return dp[i][j] = min(up,left) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return func(grid,m-1,n-1,dp);
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