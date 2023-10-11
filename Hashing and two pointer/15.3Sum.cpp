// Brute froce is simple 
// Two loops for selecting two number
// and thirs loop for selectuing the third number

// Iterate over every element to check the all three numbers sum equals to zero or niot
// If equal to zero add it to set by sorting it, So as to avoid duplicates unordered set to go inside


// Better Approach removes the work of third loop

// Use hashing to store the third element everytime
// Check for the required number is there is the hashmap or not
// If its there,sort the three number Store the three number in a data structure which doesnt accept duplicates(probably set)

// T.C = O ( N x N ) x O(log M) + O(nlogn) (Loops , finding and sorting)....it may be decrease if we use somekind of unordered set
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        
        for(int i=0;i<nums.size()-1;i++){
            set<int> hashSet;
            for(int j=i+1;j<nums.size();j++){
                int third_num = -(nums[i] + nums[j] );
                if(hashSet.find(third_num) != hashSet.end()){
                    vector<int> v = {nums[i] ,nums[j] ,third_num};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> vect{st.begin(),st.end()};
        return vect;
    }
};


// Optimal Approach

//Use two pointer Approach aka three pointer approach

// Sort the array because two pointer approach only works in sorted array
// Fix one pointer
// and make other two pointer vary
// The second pointer will be at first_pointer_position+1 and the thirs pointer will be always at last

// Inside the for loop
// Move the pointer inside teh loops and check for the sum == 0
// if it equals store the set of three numbers in a vector
// if the sum > 0 then decerease the third pointer
// if the sum < 0 then increase the third pointer 

// T.C = O ( N logN ) +  O(N x N)
// S.C = O (No. of answers)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(i=0;i<nums.size();i++){
            if(i>0 && nums[i]== nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    v.push_back({ nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return v;
    }
};