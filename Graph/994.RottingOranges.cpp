// BFS Approach only possible

// because we have to find the minimum time to rot all oranges 
// One rotten orange can rotten up to 4 fresh oranges present in its 4 directions. 


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS Traversal only
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = 2;
                    q.push({{i, j}, 0}); // row,col,time
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int time = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            // time = max(time,t);
            q.pop();
            for (int k = 0; k < 4; k++) {
                int row = r + drow[k];
                int col = c + dcol[k];
                if (row >= 0 && row < m && col >= 0 && col < n &&
                    !visited[row][col] && grid[row][col] == 1) {
                    visited[row][col] = 2;
                    q.push({{row, col}, t + 1});
                    time = t + 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
