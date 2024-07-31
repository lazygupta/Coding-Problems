// First I tried normal recursive approahc of visiting the same reuslt again and again

// This solution will igve you TLE

class Solution {
public:

    void helper(int m,int n,int *res,int row,int col,int drow[],int dcol[]){
        if(row == m-1 && col == n-1){
            *res +=1 ;
            return;
        }
        for(int index = 0;index < 2;index++){
            int nextrow = row + drow[index];
            int nextcol = col + dcol[index];
            if(nextrow >=0 && nextrow<m && nextcol>=0 && nextcol<n){
                helper(m,n,res,nextrow,nextcol,drow,dcol);
            }
        }
    }

    int uniquePaths(int m, int n) {
        int drow[] = {1,0};
        int dcol[] = {0,1};
        int res = 0;
        helper(m,n,&res,0,0,drow,dcol);
        return res;
    }
};

// Then come the magic

//DP Approach

// Assign the first row and first column dp table according to the constraints

// Then iterate over every cell and update its value according to the fist row is 1 or not


class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int col = 0; col < n; col++) {
            dp[0][col] = 1;
        }
        
        for (int row = 0; row < m; row++) {
            dp[row][0] = 1;
        }
        
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};