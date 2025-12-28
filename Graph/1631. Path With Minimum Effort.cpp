// 1631. Path With Minimum Effort
// We will use Dijkstra's algorithm to find the path with minimum effort in a grid. The effort of a path is defined as the maximum absolute difference in heights between consecutive cells in the path. We will maintain a priority queue to explore the cells with the least effort first and update the efforts for neighboring cells accordingly.
// The algorithm continues until we reach the bottom-right cell, at which point we return the minimum effort required to reach that cell.
// Note: We need to ensure that we only move to cells that are within bounds and update the effort only if we find a path with a lower maximum effort.

// We have to maintain the max effort encountered so far while moving to neighboring cells for every cell.
#include<bits/stdc++.h>
using namespace std;

// TC: O(E log V) , SC: O(N*M) for effort array and priority queue

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> efforts(m,vector<int>(n,1e8));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        efforts[0][0] = 0;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int parentEffort = it.first;
            // if(row == m-1 && col == n-1) return parentEffort;
            for(int k=0;k<4;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int childEffort = efforts[nrow][ncol];
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]) , parentEffort);
                    if(newEffort < efforts[nrow][ncol]){
                        efforts[nrow][ncol] = newEffort;
                        pq.push({newEffort , {nrow,ncol}});
                    }
                }
            }
        }
        return efforts[m-1][n-1];
    }
};