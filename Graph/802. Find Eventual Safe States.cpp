#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int>& visited,vector<int>& path, vector<vector<int>>& graph,vector<int> &check) {
        visited[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for (auto& it : graph[node]) {
            if (!visited[it]) {
                if (dfs(it, visited,path, graph,check))
                    return true;
            } else {
                if(path[it] == 1){
                    return true;
                }
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited,path, graph,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i] == 1){
                res.push_back(i);
            }
        }
        return res;
    }
};


// modified dfs cycle detection
// just check the node leads to cycle or not

class Solution {
public:
    bool dfs(int node, vector<int>& visited,vector<int>& path, vector<vector<int>>& graph,vector<int> &check) {
        visited[node] = 1;
        path[node] = 1;
        for (auto& it : graph[node]) {
            if (!visited[it]) {
                if (dfs(it, visited,path, graph,check))
                    return true;
            } else {
                if(path[it] == 1){
                    return true;
                }
            }
        }
        path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> res;
        for (int i = 0; i < V; i++) {
            // if (!visited[i]) {
                if(dfs(i, visited,path, graph,check) == false){
                    res.push_back(i);
                };
            // }
        }
        return res;
    }
};