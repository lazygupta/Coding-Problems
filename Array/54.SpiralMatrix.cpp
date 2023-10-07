// The approach is themost optimal one

// T.C = O(m x n)
// S.C = O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row=matrix.size();
        int col = matrix[0].size();
        int left=0,top=0;
        int right=col-1,bottom=row-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
            }
            
        }
        return v;
    }
};