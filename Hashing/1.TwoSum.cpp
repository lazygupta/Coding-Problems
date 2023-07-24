// The question is given an array which contains integers
// A target value is given
// We have to find two pairs equal to target value.


// These containes two type of varieties
// 1. You have to return YES or NO
// 2. You have to return the indexes of both the pairs.(remember the pair can be a subarray or subsequence).


// Brute Force Solution O(N^2)

// Better Approach - Hashing

// TC - O(N x logN) - For Map
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

// string result(vector<int> v,int target){
//     map<int,int> mpp;
//     int j=0;
//     int sum=0;
//     while(j<v.size()){

//         int rem= target - v[j];
        
//         if(mpp.find(rem) != mpp.end()){
//             return "YES";
//         }

//         mpp[v[j]] = j;

//         j++;
//     }

//     return "NO";
// }

// int main(){
//     vector<int> v{2,6,5,8,11};
//     int k=14;
//     cout<<result(v,k);
//     return 0;
// }

// Variety -2 
// Returning indices of the pairs


class Solution {
public:
    vector<int> twoSum(vector<int> &v, int target) {
    map<int,int> mpp;
    int j=0;
    int sum=0;
    while(j<v.size()){

        int rem= target - v[j];

        if(mpp.find(rem) != mpp.end()){
            return {mpp[rem], j};
        }

        mpp[v[j]] = j;

        j++;
    }

    return {-1,-1};
    }
};


// Approach 2- Two Pointer(Without using two pointer approach)

// TC  - O(N)(Traversing the array) + O(logN)(For Sorting)
// Sc - O(1)


string read(int n, vector<int> v, int target)
{
    int left=0;
    int right=n-1;

    sort(v.begin(),v.end());

    while(left<=right){
        int sum=v[left]+v[right];

        if(sum == target){
            return "YES";
        }
        
        else if(sum<target){
            left++;
        }

        else{
            right--;
        }
    }

    return "NO";
}

int main(){
    vector<int> v{3,2,4};
    int k=6;
    cout<<read(3,v,k);
    return 0;
}