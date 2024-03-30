// Basically in this question you can choose cards from front side of k length or from back side of k length
// OR from both front and back side of length k

// Intuition :- 
// Choose the leftside k length sum
// Now remove the kth element from lsum and add rightmost sum
// Decrease rightmode index and add it to lsum
// Store the maximum sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0;
        int i=0;
        int maxSum=0;
        while(i<k){
            lsum += cardPoints[i];
            maxSum = max(maxSum,lsum);
            i++;
        }
        int rindex = cardPoints.size()-1;
        for(i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxSum = max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};