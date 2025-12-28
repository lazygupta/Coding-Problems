// 743. Network Delay Time

// We have used Priority Queue to implement Dijkstra's Algorithm to find the shortest time to reach all nodes from the source node k.
// Why not Queue?   
// In Dijkstra's algorithm, we need to always expand the least costly node first to ensure that we find the shortest path to each node.
// A regular queue (FIFO) does not guarantee that the next node to be processed is the one with the smallest cumulative cost.
// A priority queue allows us to efficiently retrieve and process the node with the smallest cumulative cost at each step, which is essential for the correctness and efficiency of Dijkstra's algorithm.

// Even Queue will work but it will be less efficient as we may end up processing nodes multiple times leading to higher time complexity.

// Time Complexity: O((E + V) log V) where E is the number of edges and V is the number of vertices.
// Space Complexity: O(V + E) for storing the graph and the time array. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0,k});
        vector<int> time(n+1,1e8);
        time[k] = 0;
        while(!q.empty()){
            int sourceNode = q.top().second;
            int sourceTime = q.top().first;
            q.pop();
            if (sourceTime > time[sourceNode]) continue;
            for(auto it: adj[sourceNode]){
                int targetNode = it.first;
                int targetTime = it.second;
                if(targetTime + sourceTime < time[targetNode]){
                    time[targetNode] = targetTime + sourceTime;
                    q.push({targetTime+sourceTime,targetNode});
                }
            }
        }
        int minTime = INT_MIN;
        for(int i=1;i<time.size();i++){
            minTime = max(time[i],minTime);
            if(time[i] == 1e8) return -1;
        }
        return minTime;
    }
};