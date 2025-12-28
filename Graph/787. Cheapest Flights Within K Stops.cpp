// 787. Cheapest Flights Within K Stops

// You are given an integer n, an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from fromi to toi with cost pricei, and three integers src, dst, and k.
// Return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// We will use queue instead of priority queue to perform a modified BFS to find the cheapest flight within K stops. We will maintain an adjacency list to represent the graph and a vector to keep track of the cheapest price to reach each city. For each city, we will explore its neighbors and update their cheapest prices if we find a cheaper route within the allowed number of stops.

// Why Queue and not Priority Queue?
// In this problem, we are limited by the number of stops (k) rather than just the cost. Using a priority queue would prioritize lower costs without considering the stop constraint effectively. A standard queue allows us to explore all possible routes level by level (i.e., by number of stops), ensuring we do not exceed the k stops limit while still tracking the cheapest prices.

// TC: O(E + V) , SC: O(N + E) for adjacency list and O(N) for cheapestPrice array
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,src}}); // stops,price,node
        vector<int> cheapestPrice(n,1e8);
        cheapestPrice[src] = 0;
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int stops = it.first;
            int price = it.second.first;
            int city = it.second.second;
            for(auto it: adj[city]){
                int toCity = it.first;
                int toPrice = it.second;
                if(toPrice + price < cheapestPrice[toCity] && stops <= k){
                    cheapestPrice[toCity] = toPrice + price;
                    q.push({stops+1,{toPrice+price, toCity}});
                }
            }
        }
        if(cheapestPrice[dst] == 1e8) return -1;
        return cheapestPrice[dst];
    }
};