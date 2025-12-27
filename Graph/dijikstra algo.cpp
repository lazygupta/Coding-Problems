// Using Priority Queue (Min-Heap) for Dijkstra's Algorithm
// For Undiorected Graph with unwieghted edges

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &it: edges){
            int u= it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(V,1e8);
        dist[src]= 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            for(auto &it: adj[node]){
                int nbrNode = it;
                int nbrWt = dist[nbrNode];
                if(nbrWt > wt + 1){
                    dist[nbrNode] = wt + 1;
                    pq.push({dist[nbrNode],nbrNode});
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i] == 1e8){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

// For Undirected Graph with weighted edges

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        vector<int> dist(V,1e7);
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (wt > dist[node]) continue;
            for(auto it:adj[node]){
                int neighbour = it.first;
                int neighbourWt = it.second;
                if(wt + neighbourWt < dist[neighbour]){
                    dist[neighbour] = wt + neighbourWt;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist;
    }
};

// We are using if (wt > dist[node]) continue; to skip processing nodes that have already been found with a shorter distance. This optimization helps to avoid unnecessary work and ensures that we only process each node with its shortest known distance.
// If we don't include this check, we might end up processing the same node multiple times with longer distances, which can lead to increased time complexity.



// Case: Dense graph with repeated relaxations
// Graph construction (worst-case pattern)

// Let’s build a graph like this:

// Nodes: 0 → 1 → 2 → 3 → ... → N

// Plus direct edges from source to every node with huge weight

// 0 --100000--> 1
// 0 --100000--> 2
// 0 --100000--> 3
// ...
// 0 --100000--> N

// 0 --1--> 1 --1--> 2 --1--> 3 --1--> ... --1--> N

// Input (example for N = 5)
// V = 6
// edges = {
//   {0,1,100000},
//   {0,2,100000},
//   {0,3,100000},
//   {0,4,100000},
//   {0,5,100000},
//   {0,1,1},
//   {1,2,1},
//   {2,3,1},
//   {3,4,1},
//   {4,5,1}
// }
// src = 0

// Expected shortest distances
// 0 → 0
// 1 → 1
// 2 → 2
// 3 → 3
// 4 → 4
// 5 → 5

// Priority Queue WITHOUT the check

// ❌ No:

// if (wt > dist[node]) continue;

// What happens internally (important part)
// Step 1: From node 0

// PQ gets:

// (1,1)
// (100000,1)
// (100000,2)
// (100000,3)
// (100000,4)
// (100000,5)

// Step 2: Correct path relaxations

// Eventually:

// (2,2), (3,3), (4,4), (5,5)


// But the old big entries remain in PQ.

// The disaster 💥

// Later PQ pops:

// (100000,1)
// (100000,2)
// (100000,3)
// (100000,4)
// (100000,5)


// For each of these, you do:

// for(auto it : adj[node]) { ... }


// Even though:

// dist[node] << wt

// How bad does it get?
// For large constraints (typical GFG / LeetCode):
// V = 1e5
// E = ~2e5


// Each node may be:

// Inserted many times

// Fully expanded again and again

// Result:
// Time Complexity → O(E² log E)


// ➡ TLE
// ➡ High memory
// ➡ Unnecessary relaxations

// Same graph WITH the check
// if (wt > dist[node]) continue;

// When (100000, x) is popped:
// 100000 > dist[x]   → skip immediately


// ✔ No adjacency traversal
// ✔ No extra pushes
// ✔ Time complexity stays O(E log V)