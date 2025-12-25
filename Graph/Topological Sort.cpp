#include <bits/stdc++.h>
using namespace std;

// DFS traversal based topological sort

class Solution {
  public:
  
    void dfs(int node,stack<int> &st,vector<int> &visited,vector<vector<int>> &adj){
        visited[node] = 1;
        for(auto &it: adj[node]){
            if(!visited[it]){
                dfs(it,st,visited,adj);
            }
        }
        st.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> visited(V,0);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,st,visited,adj);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


// Kahn's Algorithm based Topological Sort

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
        