// Memorization Approach
// Same as previous question of Unique Paths

class Solution {
public:

    int solve(int row,int col,vector<vector<int>> &dp,vector<vector<int>> &v){
        if(row>=0 && col>=0 && v[row][col] == 1 ) return 0;
        if(row==0 && col==0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int up = solve(row-1,col,dp,v);
        int left = solve(row,col-1,dp,v);
        return dp[row][col] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(),col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));
        return solve(row-1,col-1,dp,obstacleGrid);
    }
};

// Tabulation Approach

class Solution {
public:

// Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(),col = obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int> (col,-1));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0 && obstacleGrid[i][j] != 1){
                    dp[i][j] = 1;
                    continue;
                }
                else{
                    int up=0,left=0;
                    if(i>0 && obstacleGrid[i][j] == 0 ) up = dp[i-1][j];
                    if(j>0 && obstacleGrid[i][j] == 0 ) left = dp[i][j-1]; 
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[row-1][col-1];
    }
};