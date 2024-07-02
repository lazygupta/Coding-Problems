// So, The prblm states that you are given with an array of +ve and -ve numbers
// You just have to store all the maximum elements of all the subarrays of size k in an seperate array

//As we all know by seeing subarrays questions we can do it using Sliding Window Algorithm
// O(n+k) , where n is the size of the array and k is variable because I am shifting the 
//sliding window everytime when arr[i] is equal to max ele

// This problem can be solve in O(n*k) by using Brute Force i.e., Nested for loop
// Here I am proceeding with the most optimal solution

//Auxillary Space = O(n-1) , n is the size of the array 

// This is done by me.

#include<bits/stdc++.h>
using namespace std;

vector<int> Maximum_Elements(int arr[], int n,int k){
    int i=0,j=0;
    int max_ele=INT_MIN;
    int sum=0;
    vector<int> v;
    while(j<n){
        if(arr[j]>max_ele){
            max_ele=arr[j];
        }

        if(j-i+1<k) j++;

        else if(j-i+1==k){ // Reaching the window size
            v.push_back(max_ele); //Pushing the maximum element uin that window

            if(max_ele == arr[i]){
                max_ele=0;
                j=i+1; //This is increasing my time complexity 
                i++; 
            }
            else{
            i++;
            j++;}
        }

    }
    return v;
}

// Done using list stl to optimise the time complexity

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0;
        list<int> li;
        int n = nums.size();
        vector<int> v;
        while(r<n){
            while(li.size()>0 && li.back()<nums[r]){
                li.pop_back();
            }
            li.push_back(nums[r]);
            if(r-l+1<k) r++;
            else if(r-l+1 == k){
                v.push_back(li.front());
                if(nums[l]==li.front())
                li.pop_front();
                l++;
                r++;
            }
        }
        return v;
    }
};