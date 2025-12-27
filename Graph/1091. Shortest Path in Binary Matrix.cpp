// Shortest Path in Binary Matrix

// We will use BFS to find the shortest path in an unweighted grid. The idea is to explore all 8 possible directions from each cell and keep track of the distance from the start cell (0,0) to each cell. If we reach the bottom-right cell (m-1,n-1), we return the distance. If we exhaust all possibilities without reaching the end, we return -1.

// Note: We need to ensure that we only move to cells that are within bounds, not blocked (value 0), and not already visited with a shorter distance.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        if(grid.size() == 1 && grid[0][0] == 0 ) return 1;
        vector<vector<int>> distance(m,vector<int> (n,1e8));
        if(grid[0][0] == 1) return -1;
        q.push({0,0});
        distance[0][0] = 1;
        int drow[8] = {-1,0,1,0,-1,-1,1,1};
        int dcol[8] = {0,1,0,-1,-1,1,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<8;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && distance[row][col] + 1 < distance[nrow][ncol] && grid[nrow][ncol] == 0){
                    distance[nrow][ncol] = distance[row][col] + 1;
                    if(nrow == m-1 && ncol == n-1) return distance[row][col]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return -1;
    }
};