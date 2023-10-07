// Better Approach

// T.C = O  (2(N x M))
// S.C = O (N+M)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return;
        if(matrix[0].size()==0) return;
        int row= matrix.size();
        int col= matrix[row-1].size();
        int rows[200]={0};
        int cols[200]={0};

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if( (rows[i]) || (cols[j]) ){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// Now think of optimal solution
// We can reduce the spafce complexity

// We can mark the element as 0 within the matrix if we take some careful steps

// First, we will traverse the matrix and mark the proper cells of 1st row and 1st column with 0 accordingly. The marking will be like this: if cell(i, j) contains 0, we will mark the i-th row i.e. matrix[i][0] with 0 and we will mark j-th column i.e. matrix[0][j] with 0.
// If i is 0, we will mark matrix[0][0] with 0 but if j is 0, we will mark the col0 variable with 0 instead of marking matrix[0][0] again.

// For marking first column
//  |
//  |
//  v
// 🎫 <--- for marking column
// 🎟️🎫🎫🎫🎫 <---- for marking column
// 🎟️🎫🎫🎫🎫
// 🎟️🎫🎫🎫🎫
// 🎟️🎫🎫🎫🎫
// 🎟️🎫🎫🎫🎫

// T.C = O (2(NxM))
// S.C = O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0= 1;
        int row = matrix.size();
        int col = matrix[0].size();
        cout<<row<<" "<<col;

        for(int i=0; i<row; i++){

            for(int j=0; j<col; j++){

                if(matrix[i][j] == 0){

                matrix[i][0]=0;

                if(j!=0){
                    matrix[0][j]=0;
                }

                else col0=0;
                }
            }
        }

        for(int i=1; i<row; i++){

            for(int j=1; j<col; j++){

                if(matrix[i][j]!=0){

                    if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){

            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }

        if(col0 == 0){
            for(int i=0; i<row; i++){
                matrix[i][0]=0;
            }
        }
    }
};