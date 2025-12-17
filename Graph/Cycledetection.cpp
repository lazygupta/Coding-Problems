
// bfs based cycle detection in an undirected graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int m = edges.size();
        vector<vector<int>> adj(V);
        for(int i =0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,int>> q;
        vector<int> visited(V, 0);
        // q.push({0,-1});
        // visited[0] = 1;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i] = 1;
                q.push({i,-1});
                while(!q.empty()){
                    int node = q.front().first;
                    int back = q.front().second;
                    q.pop();
                    for(auto it:adj[node]){
                        if(!visited[it]){
                            visited[it] = 1;
                            q.push({it,node});
                        } else{
                            if(it != back) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

// dfs based cycle detection in an undirected graph
