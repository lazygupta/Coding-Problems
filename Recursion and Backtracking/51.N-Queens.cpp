// Same intuition as Word Search
// We have to fill Q in every row and then check for valid fill that it can accomodate Q there or not

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validfill(int col, int row, vector<string> bucket, int n)
    {
        int duprow = row;
        int dupcol = col;

        // Checking Diagonally Upward Backward
        while (row >= 0 && col >= 0)
        {
            if (bucket[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;

        // Checking Horizontally Backward
        while (col >= 0)
        {
            if (bucket[row][col] == 'Q')
                return false;
            col--;
        }
        row = duprow;
        col = dupcol;

        // Checking Diagonally Downward Backward
        while (row < n && col >= 0)
        {
            if (bucket[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &res, vector<string> &bucket, int n)
    {
        if (col == n)
        {
            res.push_back(bucket);
            return;
        }

        int row = 0;
        for (row = 0; row < n; row++)
        {
            if (validfill(col, row, bucket, n))
            {
                bucket[row][col] = 'Q';
                solve(col + 1, res, bucket, n);
                bucket[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> bucket(n);
        string str(n, '.'); // Filling the string with '.'
        for (int i = 0; i < n; i++)
        {
            bucket[i] = str; // Filling the bucket with empty string of '.'
        }
        solve(0, res, bucket, n);
        return res;
    }
};