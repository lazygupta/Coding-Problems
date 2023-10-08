//Brute Force approach is to generate all the rows 
//Using the formula (n-1)C(r-1), where n is the row and r is the columns

// Formula = (r-1)C(c-1) ... This formula generate any element present at row=r and column=c

// e.g
//       1
//      1 1
//     1 2 1
//    1 4 4 1
//   1 4 6 4 1 
// 1 5 10 10 5 1

// Lets generate element using formula (r-1)C(c-1)

// r=5 and c= 3
// (5-1)C(3-1) = 4!/(2! x 2!) = 6
// r=6 and  c=4
// (6-1)C(4-1) = 5! / ( 3! x 2! ) = 10



// Brute Force Approach


// T.C = O (N x N x r) =~ O( N x N X N )
// S.C = O ( N x N )


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nCr(int row,int col){
        long long ans=1;
        for(int i=0;i<col;i++){
            ans=ans*(row-i);// Reducing the work of counting factorial
            ans=ans/(i+1);
        }
        return int(ans);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec(numRows); 
        for(int row=1;row<=numRows;row++){
            for(int col=1;col<=row;col++){
                vec[row-1].push_back(nCr(row-1,col-1));
            }
        }
        return vec;
    }
};


// Optimal Approach

// T.C = O ( N x N )
// S.C = O ( N x N )

class Solution {
public:

    vector<int> generateRows(int row){
        vector<int> ansRow;
        int ans=1;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){
            ans= ans * (row-col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vect;
        for(int i=1;i<=numRows;i++){
            vect.push_back(generateRows(i));
        }
        return vect;
    }
};