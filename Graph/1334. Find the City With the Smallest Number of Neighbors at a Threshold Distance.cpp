// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// We dont need to make a graph using adjacency list as we have to find shortest path between all pairs of nodes
// So we can use Floyd Warshall Algorithm directly on the given edges list after converting it into a matrix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e8));
        // convert list → matrix
        for (int u = 0; u < n; u++) {
            matrix[u][u] = 0;
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                matrix[u][v] = wt;
                matrix[v][u] = wt;
            }
        }
        // shortest path - floyd warshal
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        int res = -1;
        int prevCount = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            int count = 0;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] <= distanceThreshold) count++;
            }
            if(count <= prevCount) {
                res = i;
                prevCount = count;
            }
        }
        return res;
    }
};