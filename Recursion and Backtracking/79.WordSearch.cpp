#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNext(int row,int col,int index,vector<vector<char>> &board,string word) {
        if(index==word.length()){
            return true;
        }
        
        if(row<0 || col<0 || row==board.size() || col==board[0].size() || board[row][col] != word[index] || board[row][col] == '#'){
            return false;
        }

        char c= board[row][col];
        board[row][col]='#';

        bool bottom = findNext(row+1,col,index+1,board,word);
        bool right = findNext(row,col+1,index+1,board,word);
        bool top = findNext(row-1,col,index+1,board,word);
        bool left = findNext(row,col-1,index+1,board,word);

        board[row][col]=c;

        return top || bottom || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == word[0]){
                    if(findNext(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};