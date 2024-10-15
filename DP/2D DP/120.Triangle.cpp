// Just like grid, Go to every down and digonal and store the minimum value
// Build DP for memoization

// T.C = O(N*N)
// S.C = O(N)dp space + O(N*N) stack space

class Solution {
public:

    int func(vector<vector<int>>& triangle,int i,int j,int m, int n,vector<vector<int>> &dp){
        if(j>=n || i>=m) return INT_MAX;
        if(i == m-1 && j<n) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int opt1 = func(triangle,i+1,j,m,n,dp);
        int opt2 = func(triangle,i+1,j+1,m,n,dp);
        return dp[i][j] = triangle[i][j] + min(opt1,opt2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        if(m==1 && n==1) return triangle[0][0];
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return func(triangle,0,0,m,n,dp);
    }
};


// Tabulation Approach

// 1. Suppose that only the last level is given. 

// 4 1 8 3

// Then what should be your answer?

// If you thought 1, then congratulations 🎉 you are correct. This is our first subproblem. 

// 2. Now, the last two levels are given.

//  6 5 7
// 4 1 8 3

// Here, what should be the answer and what information do you need to store?

// Clearly, the answer is 6 (5 -> 1). But, this may not be the optimal path. So, we need to store all the optimal paths, i.e.,
// [(6 -> 1), (5 -> 1), 7 -> 3)] or [7, 6, 10]. This is our second subproblem.

// 3. Last 3 levels are given.

//   3 4
//  6 5 7
// 4 1 8 3

// Again, what should be the answer and what information do you need to store (or use)?

// Answer is 9 (3 -> 5 -> 1). Do we need to look again at all the paths? Can we use the information that we previously stored?
// No and Yes.
// If we replace the triangle as
//   3 4
//  7 6 10
// then also, we'll get the same answer. And we can store this information as [(3 -> 6), (4 -> 6)] or [9, 10].

// 4. All levels are given

//    2
//   3 4
//  6 5 7
// 4 1 8 3

// Which can be replaced as:
//    2
//   9 10

// And hence, our answer is 11 (2 -> 9)

class Solution {
public:
// Tabulation Approach
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        if(m==1 && n==1) return triangle[0][0];
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int j=0;j<m;j++) { // We are starting from bottom 
            dp[m-1][j] = triangle[m-1][j];
        }
        for(int i= m-2; i>=0 ; i--){
            for(int j =0;j<triangle[i].size();j++){
                int opt1 = INT_MAX,opt2 = INT_MAX;
                opt1 = dp[i+1][j];
                if(j<triangle[i].size()) opt2 = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(opt1,opt2);
            }
        }
        return dp[0][0];
    }
};