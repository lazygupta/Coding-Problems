// The sorted array having distinct element is rotated at any index 

// we have to search an element and return its index.
// This can be done using Linear Search
// Brute Force - O(N) - Using Linear Search

// Optimal approach- O(log N) - using Binary Search\
// T.C = O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;

        while(low<= high ){
            
            int mid = low + (high - low) /2;

            if(arr[mid] ==  target ) return mid;

            if( arr [low] <= arr[mid] ){
                if(arr[low] <= target && target <= arr[mid] ){
                    high = mid -1;
                }
                else low =mid+1;
            }

            else {
                if(arr[mid ] <= target && target <= arr[high]){
                    low = mid+1;
                }
                else high = mid -1;
            }

            
        }

        return -1;
    }
};


// Nwo the variety 2 comes in where you are given aith an array with not distinct element

// The array is sorted but rotated at any index.

// Search the element in O(log N) time

// Our above code will work but not for a particular edge case

// Suppose arr[]= {1,0,1,1,1}
// Search for 0;

// Then the comparision cant be done with the mid low and high element
// i.e., arr[mid]=arr[low]=arr[high] -> Wrong result


class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size()-1;

        while(low<= high ){
            
            int mid = low + (high - low) /2;

            if(arr[mid] ==  target ) return mid;

            if(arr[mid] == arr[ low] && arr[mid ]== arr[high]){
                high--;
                low++;
                continue;
            } 
            
            if( arr [low] <= arr[mid] ){
                if(arr[low] <= target && target <= arr[mid] ){
                    high = mid -1;
                }
                else low =mid+1;
            }

            else {
                if(arr[mid ] <= target && target <= arr[high]){
                    low = mid+1;
                }
                else high = mid -1;
            }

            
        }

        return -1;
    }
};
