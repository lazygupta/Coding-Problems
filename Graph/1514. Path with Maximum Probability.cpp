// 1514. Path with Maximum Probability
// same as Dijkstra's Algorithm
// We have used Priority Queue to implement Dijkstra's Algorithm to find the path with maximum probability from start_node to end_node.
// Why not Queue?   
// In Dijkstra's algorithm, we need to always expand the most probable node first to ensure that we find the path with maximum probability to each node.
// A regular queue (FIFO) does not guarantee that the next node to be processed is the one with the highest cumulative probability.
// A priority queue allows us to efficiently retrieve and process the node with the highest cumulative probability at each step, which is essential for the correctness and efficiency of Dijkstra's algorithm.
// Even Queue will work but it will be less efficient as we may end up processing nodes multiple times leading to higher time complexity.
// Time Complexity: O((E + V) log V) where E is the number of edges and V is the number of vertices.
// Space Complexity: O(V + E) for storing the graph and the probability array.


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