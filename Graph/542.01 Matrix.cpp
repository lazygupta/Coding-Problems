#include<bits/stdc++.h>
using namespace std;


// BFS Traversal to find the distance of nearest 0 for each cell in matrix
// Same as Rotting Oranges question

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int d = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int k=0;k<4;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<m && ncol >=0 && ncol<n && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
    }
};