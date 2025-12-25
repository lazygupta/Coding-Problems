#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
  
  void dfs(int node,vector<vector<pair<int,int>>> adj, vector<int> &visited, stack<int> &st ){
      visited[node] = 1;
      for(auto it: adj[node]){
          if(!visited[it.first]){
              dfs(it.first,adj,visited,st);
          }
      }
      st.push(node);
  }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            // cout<<edges[i][0]<<"->"<<edges[i][1]<<","<<edges[i][2]<<endl;
        }
        
        stack<int> st;
        vector<int> visited(V,0);
        
                dfs(0,adj,visited,st);
        // 2nd find distance
        vector<int> dist(V,1e7);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
               for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                } 
        }
        
        for(int i=0;i<dist.size();i++){
            if(dist[i] == 1e7){
                dist[i] = -1;
            }
        }
        return dist;
    }
};
