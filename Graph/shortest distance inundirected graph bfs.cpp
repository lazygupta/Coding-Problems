#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(src);
        vector<int> shortestDist(V,1e7);
        shortestDist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it: adj[node]){
                if(shortestDist[it] > shortestDist[node]+1){
                    shortestDist[it] = shortestDist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<shortestDist.size();i++){
            if(shortestDist[i] == 1e7){
                shortestDist[i] = -1;
            }
        }
        return shortestDist;
    }
};
