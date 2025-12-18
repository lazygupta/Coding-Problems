#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int m ,int n,int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid){
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        visited[row][col] = 1;
        for(int k=0;k<4;k++){
            int r = row + drow[k];
            int c = col + dcol[k];
            if(r>=0 && r<m && c>=0 && c<n && !visited[r][c] && grid[r][c] == 1){
                dfs(m,n,r,c,visited,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        //checking boundaries only
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1 && !visited[0][i]){
                dfs(m,n,0,i,visited,grid);
            }
            if(grid[m-1][i] == 1 && !visited[m-1][i]){
                dfs(m,n,m-1,i,visited,grid);
            }
        }
        // for cvolumns
        for(int i=0;i<m;i++){
            if(grid[i][0] == 1 && !visited[i][0]){
                dfs(m,n,i,0,visited,grid);
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1]){
                dfs(m,n,i,n-1,visited,grid);
            }
        }
        int count = 0;
        //marking number of kand cells left safe
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] != 1 && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};