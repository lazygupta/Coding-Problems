
// dfs solution for bipartite graph
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int i, vector<int>& color, vector<vector<int>>& graph,
             int intColor) {
        int initialColor = intColor;
        color[i] = initialColor;
        for (auto it : graph[i]) {
            if (color[it] == -1) {
                if (!dfs(it, color, graph, !intColor))
                    return false;
            } else if (color[it] == initialColor)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
    // bipartite means it should follow bi-color rule
    int V = graph.size();
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!dfs(i, color, graph, 0)) {
                return false;
            }
        }
    }
    return true;
}
}
;

// bfS solution for bipartite graph

class Solution {
public:
    bool bfs(int i, vector<int>& color, vector<vector<int>>& graph,
             int intColor) {
        queue<int> q;
        q.push(i);
        color[i] = intColor;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // bipartite means it should follow bi-color rule
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!bfs(i, color, graph, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};