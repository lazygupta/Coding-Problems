// Brute Approach

// T.C = O(N x N)
// S.C = O(N x N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector <vector<int>> ans(n, vector < int > (n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=ans;
    }
};

// Optimal Approach
// T.C = O(N*N)
// S.C = O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<i;j++){
                // if(i!=j){
                    swap(matrix[i][j],matrix[j][i]);
                // }
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
