// Very easy question
// Brute force solution would be using nested loop

// T.C =  (NXM)


#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int result=-1;
    int count=0,max_count=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1){
                count++;
            }
        }
        if(count>max_count){
            result=i;
            max_count=count;
        }
    }
    return result;
}

// Now using binary search we woukd be reducing the second loop 

// T.C = (NxlogM)

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int result=-1;
    int max_count=0;
    for(int i=0;i<n;i++){
        int low=0,high=m-1;
        while(low<=high){
            int mid = low+ (high - low) /2;
            if(matrix[i][mid] == 1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if((m-low) > max_count){
            max_count=(m-low);
            result=i;
        }
    }
    return result;

}