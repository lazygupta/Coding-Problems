// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Using Two- Pointer Approach

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxi=0, prod= 0;
        while(left<=right){

            prod = min(height[left],height[right]) * (right - left );

            maxi = max (prod,maxi) ; 

            if(height[left] <= height [right]){
                left++;
            }

            else right--; 
        }

        return maxi;
    }
};


