// Again done this questiona ccording to Strivers

// Recursion Approach
// Verdict:- TLE

class Solution {
public:

    int solve(int row,int col){
        if(row==0 && col ==0){
            return 1;
        }
        if(row<0 || col<0) return 0;
        int up = solve(row-1,col);
        int left = solve(row,col-1);
        return up + left;
    }

    int uniquePaths(int m, int n) {
        int row,col;
        return solve(m-1,n-1);
    }
};

// Will try memoization using dp array
// T.C = O(m*n)
// S.C = O((N-1)+(M-1)) + O(M*N)
class Solution {
public:

    int solve(int row,int col,vector<vector<int>> &dp){
        if(row==0 && col ==0){
            return 1;
        }
        if(row<0 || col<0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int up = solve(row-1,col,dp);
        int left = solve(row,col-1,dp);
        return dp[row][col] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,dp);
    }
};


// Tabulation Method
// T.C = O(M*N)
// S.C = O(M*N)

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            dp[0][i] = 1; 
        }
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j = 1;j<n;j++){
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }

// 2nd Way

class Solution {
public:
    int uniquePaths(int row, int col) {
        vector<vector<int>> dp(row,vector<int> (col,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0 && j ==0){
                    dp[0][0] = 1;
                    continue;
                }
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[row-1][col-1];
    }
};


// This I have solved earlier

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