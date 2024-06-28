class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row_min=INT_MAX,row_max=INT_MIN;
        int col_min=INT_MAX,col_max=INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    row_max = max(i,row_max);
                    row_min = min(i,row_min);
                    col_max = max(j,col_max);
                    col_min = min(j,col_min);
                }
            }
        }
        int row = (row_max - row_min) + 1;
        int col = (col_max - col_min) + 1;
        return (row*col);
    }
};