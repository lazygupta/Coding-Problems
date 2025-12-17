#include<bits/stdc++.h>
using namespace std;

// dfs traversal to find number of provinces

class Solution {
public:
    void dfs(int start, vector<int> &visited,vector<vector<int>> &adj) { 
        visited[start] = 1;
        for(auto it: adj[start]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }

    void conversion(vector<vector<int>> &adj,
                    vector<vector<int>>& isConnected) {
        for (int i = 0; i < isConnected.size(); i++) {
            for(int j = 0; j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        conversion(adj, isConnected);
        vector<int> visited(adj.size(), 0);
        int count = 0;
        for (int i = 0; i < adj.size(); i++) {
            if (!visited[i]) {
                // cout<<i<<" ";
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};


// bfs traversal to find number of provinces

class Solution {
public:
    void bfs(int start, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    void conversion(vector<vector<int>>& adj,
                    vector<vector<int>>& isConnected) {
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        conversion(adj, isConnected);

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, visited, adj);
            }
        }
        return count;
    }
};