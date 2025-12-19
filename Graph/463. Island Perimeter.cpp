#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + drow[k];
                        int ncol = j + dcol[k];
                        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                            grid[nrow][ncol] == 1) {
                            count++;
                        }
                    }
                    ans += 4-count;
                }
            }
        }
        return ans;
    }
};