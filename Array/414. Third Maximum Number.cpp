// Simple add the element in priority queue
// Stay alert when you are adding duplicate element

// Pop two elements from the priority queue
// If the pq is not empty the pq.top will be the result always

// Q) why can't use heap?
// Because heap gives kth smallest/largest that come in sequence assuming sorted array, not the kth distinct smallest/largest.

// T.C = O(NlogN)
// S.C = O((N))

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            priority_queue<int> pq;
            pq.push(nums[0]);
            for(auto it: nums){
              if(it != pq.top()){
                pq.push(it);
              }
            }
            int count = 0;
            while(!pq.empty()){
              count++;
              pq.pop();
              if(count == 2) break;
              
            }
            if(!pq.empty()) return pq.top();
            else return nums[nums.size()-1];
        }
    };

// A better approach , not using priiority queue

// T.C = O(NlogN)
// S.C = O(1)

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int largest = nums[nums.size() - 1];
            if (nums.size() == 2) {
                return largest;
            }
            int count = 1;
            for (int i = nums.size() - 1; i > 0; i--) {
                if (nums[i] != nums[i - 1]) {
                    count++;
                    if (count == 3)
                    return nums[i-1];
                }
            }
            return largest;
        }
    };

// 3rd method

// Doing it by using ther logic for 2nd maximum number(GFG)

// Long long is taken to avoid this case
// [1,2,-2147483648]
// If we will take int_min then the third maximum will never be returned correctly being the correct answer too


class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            long long firstMax = LLONG_MIN, secondMax = LLONG_MIN, thirdMax = LLONG_MIN;
            for(auto it: nums){
              if(it> firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = it;
              }
              else if(it> secondMax && it!= firstMax){
                thirdMax = secondMax;
                secondMax = it;
              }
              else if(it > thirdMax && it!= secondMax && it!= firstMax){
                thirdMax = it;
              }
            }
            return (thirdMax != LLONG_MIN) ? thirdMax : firstMax;
        }
    };

