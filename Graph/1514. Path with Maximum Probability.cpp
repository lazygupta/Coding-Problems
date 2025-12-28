// 1514. Path with Maximum Probability

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double succ = succProb[i];
            adj[u].push_back({v,succ});
            adj[v].push_back({u,succ});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
        pq.push({1.0,start_node});
        vector<double> path(n,0.0);
        path[start_node] = 1.0;
        while(!pq.empty()){
            double probab = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int trgtNode = it.first;
                double probTrgtNode = it.second;
                if(path[trgtNode] < probab*probTrgtNode){
                    path[trgtNode] = probab*probTrgtNode;
                    pq.push({probab*probTrgtNode,trgtNode});
                }
            }
        }
        return path[end_node] == 0.0 ? 0 : path[end_node] ;
    }
};