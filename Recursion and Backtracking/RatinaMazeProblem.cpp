// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
  
    void solve(int row,int col,vector<vector<int>> &mat,int n,
    vector<string> &res,vector<vector<int>> &visited,string str,int di[],int dj[]){
        if(row==n-1 && col == n-1){
            res.push_back(str);
            return;
        }
        string direction = "DLRU";
        for(int i=0;i<4;i++){
            int nextrow = row + di[i];
            int nextcol = col + dj[i];
            if(nextrow>=0 && nextrow<n && nextcol>=0 && nextcol<n && !visited[nextrow][nextcol] && mat[nextrow][nextcol]==1){
                visited[row][col] = 1;
                solve(nextrow,nextcol,mat,n,res,visited,str+direction[i],di,dj);
                visited[row][col]=0;
            }
        }
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> res;
        int n = mat.size();
        int drow[] = {1,0,0,-1};
        int dcol[] = {0,-1,1,0};
        vector<vector<int>> visited(n,vector<int> (n,0));
        if(mat[0][0] == 1) solve(0,0,mat,n,res,visited,"",drow,dcol);
        return res;
    }
};