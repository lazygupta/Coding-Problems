// We have to buy stocks and check the profit on which day I can sell to  maximise profit
// Think it reverse way, On which day I have to sell it to maximise the profit

// So to maximise your profit you have to sell it on the previous minimum buying day.

// Optimal Approach - O(N)
// SC - O(1)

// This is question related to DP

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Profit(vector<int>& prices) {
        int cost=0,maxProfit=0;
        int minBuying=prices[0]; // Let the minimum buying at 1st day
        // To maximise the profit
        // I have to keep track of minimum buying price on the previous days
        int i=0;
        while((i)<prices.size()){
            cost = prices[i] - minBuying;
            maxProfit = max( maxProfit , cost);
            minBuying = min  ( minBuying , prices [i]);
            i++;
        }
        return maxProfit;
    }
};

int main() {
    vector<int> arr = {8,7,6,6,6,6,6};
    Solution ob;
    int maxPro = ob.Profit(arr) ;
    cout << " Max profit is: " << maxPro << endl;
}