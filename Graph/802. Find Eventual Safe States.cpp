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

// bfs method (Kahn's Algorithm - Topological Sort)


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // So now this we will solve by Kahn's Algo
        // Starting from terminal node only.
        // We have to reverse the graph first;
        vector<int> indegree(graph.size(),0);
        vector<vector<int>> adj(graph.size());
        for(int i =0;i<graph.size();i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};
