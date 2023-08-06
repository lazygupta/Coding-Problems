// Brute force would be very easy

// Just iterate over every array elements
// Calculate the frequencty and then display it if it is gretaer tha n/4

// T= O(N^2) 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: int findSpecialInteger(vector<int> arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[i] == arr[j]) count++;
            }
            if(count > n / 4) return arr[i];
        }
        return -1;
    }
}

// Best Approach
// Using frequency or hashmap to store the frequnecy of the array elements

// T = O(N) , S = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    int findSpecialInteger(vector<int> arr) {
        int n = arr.size();
        int freq[] ={0};
        for(int i : arr) {
            freq[i]++;
        } 
        for(int i = 0; i < freq.length; i++) {
            if(freq[i] > n / 4) return i;
        }
        return -1;
    }
}


// Another Aproach

// T= O(N) & S=O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& v) {
        int t=v.size()/4;

        for(int i=0;i<(v.size())-t;i++){
            if(v[i]==v[i+t]){
                return v[i];
            }
        }
        return -1;
    }
};

// Optimal Approach

// Now we will try to use binary search for this question

// Divide array into four parts because we need to have every 25% of the array in each parts
// Our target element would be in any of the part of array
// Because the target element is having more tham 25% partnership in array

// So divide the array in 4 parts
// Search for the first occurence index of the element 
// Again check if the first occurence index element is equal to index+4 element
// If yes that return that element

// T = O(3 * log N)
// S = O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int firstIndex(vector<int> v,int ind){
        int n= v.size();
        int start=0, end=n-1;
        int ans=-1;
        while(start<=end ){
            int mid = start + (end- start) /2;

            if(v[mid]>=v[ind]){
                ans=mid;
                end = mid -1;
            }

            else start = mid +1;
        }
        return ans;
    }
    bool valid(vector<int> v,int ind) {
        int n = v.size();
        int start = firstIndex( v,ind);
        if(v[start + (n / 4)] == v[ind]) return true;
        return false;
    }

    int findSpecialInteger(vector<int> &v) {
        int n = v.size();
        int first = n / 4;
        int second = n / 2;
        int third = 3 * n / 4;
        
        if(valid(v, first)) return v[first];
        else if(valid(v, second)) return v[second];
        else if(valid(v, third)) return v[third];
        return -1;
    }
};