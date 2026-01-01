// Bellman-Ford Algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph.
// negative weight cycles are also detected in this implementation.
// Time Complexity: O(V*E) where V is the number of vertices and E is the number of edges.

#include<bits/stdc++.h>     
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u= it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
            if(i==V-2){
                for(auto it: edges){
                    if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                        return {-1};
                    }
                }
            }
        }
        return dist;
    }
};
