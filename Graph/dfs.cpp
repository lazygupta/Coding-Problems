#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  void dfsTraversal(int start, vector<vector<int>>& adj,vector<int> &visited,vector<int> & res){
      res.push_back(start);
      visited[start] = 1;
      for(auto it: adj[start]){
          if(!visited[it])
          dfsTraversal(it,adj,visited,res);
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> visited(adj.size(), 0);
        vector<int> res;
        int start;
        dfsTraversal(start,adj,visited,res);
        return res;
    }
};