#include<bits/stdc++.h>
using namespace std;


// BFS Approach to Flood Fill Algorithm
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // without tampering original array
        queue<pair<int,int>> q;
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited = image;

        q.push({sr,sc});

        visited[sr][sc] = color;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol] != color && image[nrow][ncol] == originalColor ) {
                    visited[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }

        return visited;
    }
};

//DFS Approach to Flood Fill Algorithm

class Solution {
public:

    void dfs(int sr,int sc,int drow[],int dcol[], int originalColor, int color,vector<vector<int>> &image, vector<vector<int>> &visited) {
        visited[sr][sc] = color;
        for(int i =0 ;i<4; i++){
            int row = sr + drow[i];
            int col = sc + dcol[i];
            if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && visited[row][col] != color && image[row][col] == originalColor){
                dfs(row,col,drow,dcol,originalColor,color,image,visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> visited = image;

        // trying dfs traversal to modify the array

        dfs(sr,sc,drow,dcol,originalColor,color,image,visited);

        return visited;
    }
};