// cycle detection in directed graph using dfs
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  bool dfs(int node,vector<int> &visited,vector<vector<int>> &adj,vector<int> &pathVisited){
      visited[node] = 1;
      pathVisited[node] = 1;
      for(auto it: adj[node]){
          if(!visited[it]){
              if(dfs(it,visited,adj,pathVisited)){
                  return true;
              }
          } else {
              if(pathVisited[it] == 1){
                  return true;
              }
          }
      }
      pathVisited[node] = 0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited,adj,pathVisited)) return true;
            }
        }
        return false;
    }
};