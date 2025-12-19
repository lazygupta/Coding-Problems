// VVI question

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void bfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>> &grid,vector<pair<int,int>> &res,int row0,int col0){
        int drow[4] = {1, -1, 0, 0};
        int dcol[4] = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        res.push_back({row-row0,col-col0});
        queue<pair<int, int>> q;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = r + drow[k];
                int ncol = c + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    res.push_back({nrow-row0,ncol-col0});
                    q.push({nrow,ncol});
                }
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        set< vector <pair<int,int>> > shape;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<pair<int,int>> res;
                    bfs(i,j,visited,grid,res,i,j);
                    shape.insert(res);
                }
            }
        }
        return shape.size();
    }
};


// DFS approach

class Solution {
  public:
  
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>> &grid,vector<pair<int,int>> &res,int row0,int col0){
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        res.push_back({row-row0,col-col0});
            for(int k=0;k<4;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    dfs(nrow,ncol,visited,grid,res,row0,col0);
                }
            }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        set< vector <pair<int,int>> > shape;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<pair<int,int>> res;
                    dfs(i,j,visited,grid,res,i,j);
                    shape.insert(res);
                }
            }
        }
        return shape.size();
    }
};

