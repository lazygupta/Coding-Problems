// The mssing number should be find in an array 

// Brute force intuiton seems to bit tough but its easy
// Just check the elements should be always less than the required number of missing number and increase the k
// If it exceeds return k

// T.C = O(N)
// S.C = (1)

// 2 3 4 7 11
// k=5
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
            
    }
};


// 2nd Approach
// As we can see our answers will be surely lying in between the numbers from 0 to array size

// So we can apply binary search here

// Traverse from 0 to array size
// We have to find the missing elements neighbours as soon as we found out the neighbours
// Add the required missing number numbe in it

// e.g 2 3 4 7 11
// k= 5
// The fifth missing number should be found between 7 and 11

// 1 2 3 4 _ _ 7 _ _ _  11
// 1 2 3 4 5 6 7 8 9 10 11
// 2 3 4 7 11 ---> original array

// the fifth missing number is to be found between 7 and 11
// Now till 7 there are 3 missing numbers
// How more we want??? -----> The answer is two more
// Just add two to 7 -----> 7+2 = 9
// bnow the question arises how to find the index of the neighbours
// We will use binary search for that

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        int missing = 0;// for keeping the count of missing no.
        while(low<=high){
            int mid = low + (high- low)/2; //  0+4/2=2 // 3 //8/2=4

            missing = arr[mid] - ( mid +1 ); // 4-(3)=1 // 3 // 11-(5) = 6

            if ( missing < k ) low = mid+1; // low = 3 // 4

            else high = mid-1; // 3
        }
        // Now we will see when the loop will exit
        // Then the high will be always less than low
        // in this case high = 3 and low = 4
        // return arr[high] + (missing number needed more);
        // So we will try to reduce because this will be giving runtime error for teste case
        // {    4 ,  5, 6, 7} k=3
        //  |   |
        //  |   |
        // high |
        //     low
        // the high would be pointing in a null index
        // So reducing arr[high] + k - (missing number at high);
        // We get, arr[high] + k - (arr[high] - (high +1)) // Formula for missing number - arr[high] - (high +1)
        // arr[high] + k - arr[high] + high + 1;
        // k + high + 1
        // k +(low-1) +1;
        // k + low;

        return low+k;

    }
};