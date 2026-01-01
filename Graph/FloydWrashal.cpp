// Floyd Warshall Algorithm to find shortest distance between every pair of vertices in a weighted graph.
// Time Complexity: O(V^3) where V is the number of vertices.   
#include<bits/stdc++.h>     
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &cost) {
        // Code here
        int n = cost.size();
        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j] = min(cost[i][j] , cost[i][via] + cost[via][j]);
                }
            }
        }
    }
};