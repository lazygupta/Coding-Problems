// First and last occurence of a number in an array

// the brute force and better takes O(N) T.C

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int first=-1,last =-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==target){
                if(first== -1) first = i;
                last =i;
            }
        }

        return {first,last};
    }
};

// Now the optimal approach comes into work

// We can solve this using Binary Search


class Solution {
public:

    int FirstOccurence(vector<int> &v, int target){
        int low =0, high =v.size()-1;
        int first=-1;
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(v[mid] == target ){
                high = mid -1;
                first = mid;
            }

            else if(v[mid]<= target){
                low = mid+ 1;
            }

            else high = mid -1;
        }
        return first;
    }

    int LastOccurence(vector<int> &v, int target){
        int low =0, high =v.size()-1;
        int last=-1;
        while(low <= high){

            int mid = low + (high - low) / 2;

            if(v[mid] == target ){
                low = mid + 1;
                last = mid;
            }

            else if(v[mid] <= target){
                low = mid+ 1;
            }

            else high = mid -1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& arr, int target){
        int first= FirstOccurence(arr,target);
        if(first==-1) return {-1,-1};
        int last = LastOccurence(arr,target);
        return {first,last};
    }

    // To find the occurence of element in an array
    // Just minus the first and last occurence and add plus 1 in it
        
};

// Another Approach without Binary Search but T.C = O(N) + O(N) = O(2N)
// S.c =m O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int>ans;
        int low=-1;
        int high=-1;
        auto it=find(nums.begin(),nums.end(),target);
        if(it!=nums.end()){
        low= it-nums.begin();// The position where element is foound - first position
        }
        cout<<low;

        if(low!=-1){
            for(auto i=it;i!=nums.end();i++){
                if(*i==target){
                    high=i-nums.begin();
                }
            }
        }
        ans.push_back(low);
        ans.push_back(high);
        return ans;
    }
        
};