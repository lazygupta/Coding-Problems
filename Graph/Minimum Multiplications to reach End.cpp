// We are given an array of integers arr and two integers start and end.
// We need to find the minimum number of multiplications required to reach from start to end.
// In one multiplication, we can multiply the current number with any element of the array arr and take modulo 100000.

// if(step > steps[node]) continue; this is not necessary as we are using simple queue not priority queue
// but it is an optimization to skip processing nodes that have already been reached in fewer steps.
#include <bits/stdc++.h>    
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> pq;
        pq.push({0,start});
        vector<int> steps(100000,1e9);
        steps[start] = 0;
        int mod = 100000;
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int step = it.first;
            int node = it.second;
            if(step > steps[node]) continue;
            if(end == node) return step;
            for(auto it: arr){
                int num = (it*node)%mod;
                if(steps[num] > step + 1){
                    steps[num] = step + 1;
                    pq.push({step+1,num});
                }
            }
        }
        return -1;
    }
};
