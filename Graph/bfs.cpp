#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> visited(adj.size(), 0);
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node]) {
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return res;
    }
};