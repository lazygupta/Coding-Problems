#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = row + drow[k];
            int ncol = col + dcol[k];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // First & last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(0, j, visited, board);
            }
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
                dfs(m - 1, j, visited, board);
            }
        }

        // First & last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, visited, board);
            }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                dfs(i, n - 1, visited, board);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// bfs traversal
class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        visited[row][col] = 1; 
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && board[nrow][ncol] == 'O'){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // First & last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                bfs(0, j, visited, board);
            }
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) {
                bfs(m - 1, j, visited, board);
            }
        }

        // First & last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                bfs(i, 0, visited, board);
            }
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) {
                bfs(i, n - 1, visited, board);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
