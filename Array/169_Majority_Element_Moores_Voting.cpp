// Majority element is the element which occurs more than n/2 times in an array

// Brute forces solution takes O(N^2) 
// Counting the each element using nested loops

// Better Approach using Hashing
// TC - O(N log N) + O(N)
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int> mpp;
//         int mx=0;
//         for(int i=0; i<nums.size() ;i++){
//             mpp[nums[i]]++;
//         }

//         for(auto it:mpp){
//             if(it.second > (nums.size()/2)){
//                 return it.first;
//             }
//         }
//         return 0;
//     }
// };



// Now the most optimal solution

// The most famous algorithm Moore's Voting Algorithm
// We will pick the element one by one
// Then will traverse the array and count the same number
// If at any position count becomes zero
// Change the element and again traverse from the same position

int Majority(vector<int> v){
    int i=0,count=0;
    int el;
    for(i=0;i<v.size();i++){
        if(count==0){
            count =1;
            el=v[i];
        }

        else if(v[i]==el){
            count++;
        }

        else count--;
    }
    count=0;
    for(i=0;i<v.size();i++){
        if(v[i]==el){
            count++;
        }
        if(count>(v.size()/2)){
            return el;
        }
    }
    return -1;
}

int main(){
    vector<int> v{7,7,5,6,5,1,5,7,5,5,7,7,5,5,5,5};
    cout<<Majority(v);
    return 0;
}


// If the questions states that there must be a majority element in array
// the we can directly return the element