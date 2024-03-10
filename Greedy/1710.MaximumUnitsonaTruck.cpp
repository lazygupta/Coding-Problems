// Based on Knapsack Problem
// No fractional allowed

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& item1, vector<int>& item2) {
        return item1[1] > item2[1];
    }

    int maximumUnits(vector<vector<int>>& items, int truckSize) {
        sort(items.begin(), items.end(), comparator);
        int value = 0;
        int curr_wt = 0;
        for (auto boxes: items) {
            if(boxes[0] + curr_wt <= truckSize){
                curr_wt += boxes[0];
                value += (boxes[1]*boxes[0]);
            }
            else{
                int rem = truckSize - curr_wt;
                value += rem * boxes[1];
                break;
            }
        }
        return value;
    }
};