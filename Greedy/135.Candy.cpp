// Intuition
// Start from left to right and then check the right neighbour
// IF right is greater than left neighbour, Set right value = Value of left and right 
// After doing this again do from right to left
// IF left is greater than right neighbour, Set left value = Value of left and right
// Now have the maximum from each array and add them

// T.C = O(N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> l2r(ratings.size(), 1);
        vector<int> r2l(ratings.size(), 1);
        int i=1;
        while(i<ratings.size()){
            if(ratings[i-1] < ratings[i]){
                l2r[i]+= l2r[i-1];
            }
            i++;
        }
        i = ratings.size() -1;
        while(i > 0){
            if(ratings[i] < ratings[i-1]){
                r2l[i-1]+= r2l[i];
            }
            i--;
        }
        int result =0 ;
        for(int i=0;i<ratings.size();i++){
            result += max(l2r[i],r2l[i]);
        }
        return result;
    }
};