// Brute Force

// Tc = O(n2)
// Sc = O(n2)

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;
        int max = grid.size() * grid[0].size();
        int row = 0 , col = 0;
        int sum = 0;
        int a = 0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(st.find(grid[i][j]) == st.end()){
                    st.insert(grid[i][j]);
                    sum += grid[i][j];
                } else {
                    a = grid[i][j];
                }
                
            }
        }
        int missing = (max*(max+1))/2 - sum;
        return {a,missing};
    }
};

// Using Maths

// SC = O(1)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long S = 0;
        long long S2 = 0;
        int size = grid.size();
        int n = size * size;
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                long long val = grid[row][col];
                S += val;
                S2 += (val * val);
            }
        }
        long long v1 = S - SN;       // a - b
        long long v2 = S2 - S2N;     // a² - b²

        long long a_plus_b = v2 / v1;
        long long a = (v1 + a_plus_b) / 2;
        long long b = a - v1;

        return {(int)a, (int)b}; 
    }
};