// dfs traversal to find number of islands

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == '0' || visited[row][col]) {
            return;
        }
        visited[row][col] = 1;
        dfs(row + 1, col, grid, visited);
        dfs(row - 1, col, grid, visited);
        dfs(row, col + 1, grid, visited);
        dfs(row, col - 1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << visited[i][j] << " ";
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    res += 1;
                }
            }
        }
        return res;
    }
};

// bfs traversal to find number of islands

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        int delRow[4] = {1, -1, 0, 0};
        int delCol[4] = {0, 0, 1, -1};
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];
                if (nrow >= 0 && nrow < grid.size() && ncol < grid[0].size() &&
                    ncol >= 0 && !visited[nrow][ncol] &&
                    grid[nrow][ncol] == '1') {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(i, j, grid, visited);
                    res += 1;
                }
            }
        }
        return res;
    }
};

// Connected COmponents in an Undirected Graph

// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution {
  public:
  
  void dfs(int start,vector<int> &visited, vector<vector<int>> &adj,vector<int> &component){
      component.push_back(start);
      visited[start] = 1;
      for(auto it: adj[start]){
          if(!visited[it]){
              dfs(it,visited,adj,component);
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> ans;
        
        vector<int> visited(V,0);
        vector<vector<int>> adj(V);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0;i<V;i++) {
            if(visited[i] == 0){
                vector<int> component;
                dfs(i,visited,adj,component);
                ans.push_back(component);
            }
        }
        
        return ans;
        
    }
};