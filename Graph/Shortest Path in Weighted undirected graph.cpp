// Use Priority queue (Min-Heap) for Dijkstra's Algorithm
// For Undirected Graph with weighted edges
// Use parent array to store the parent of the node of shortest path, Use ad memoization to store the shortest path from source to destination

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
        vector<int> dist(n+1,1e8);
        dist[1] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(wt > dist[node]) continue;
            for(auto it: adj[node]){
                int nbrNode = it.first;
                int nbrWt = it.second;
                if(wt + nbrWt < dist[nbrNode]){
                    dist[nbrNode] = wt + nbrWt;
                    pq.push({dist[nbrNode],nbrNode});
                    parent[nbrNode] = node;
                }
            }
        }
        if(dist[n] == 1e8) return {-1};
        int node = n;
        vector<int> res;
        while(parent[node] != node){
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(1);
        res.push_back(dist[n]);
        reverse(res.begin(),res.end());
        return res;
    }
};