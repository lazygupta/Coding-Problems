// The numbers in the array is in th erange [1-n] only.

// T.C = O(N)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num]<0) return num;
            nums[num]= -nums[num];
        }
        return -1;
    }
};


// Same queston 217. Contains Duplicate
// The array has duplicate numbers

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(auto i:nums){
            hset.insert(i);
        }
        return (nums.size()!=hset.size());
    }
};

// Highly optimised and impressive solution related to linked list

// Fast Slow Pointers
// This problem is as same as 142. Linked List Cycle II, you can refer to this solution for the explanation of the slow fast pointer approach to solve this problem.

// The key is to understand how to treat the input array as a linked list.

// Take the array [1,3,4,2] as an example, the index of this array is [0,1,2,3], we can map the index to the nums[n].

// 0→1→3→2→4→invalid so no cycle

// Start from nums[n] as a new index, and so on, until the index exceeds the bounds. This produces a sequence similar to a linked list.

// 0→1→3→2→4→null

// If there are a repeated numbers in the array, take the array [1,3,4,2,2] as an example,

// 0→1→3→2→4→2→4→2

// Similarly, a linked list is like that:

// 0→1→3→2→4→2→4→2→…

// Here 2→4 is a cycle, then this linked list can be abstracted as the following figure:

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            // cycle detection technique
    
            int slow = 0;
            int fast = 0;
            while(true){
              slow = nums[slow];
              fast = nums[nums[fast]];
              if(slow == fast) break;
            }
            cout<<slow<<" "<<fast<<endl;
            slow = 0;
            while(slow!=fast){
              slow = nums[slow];
              fast = nums[fast];
            }
            cout<<slow<<" "<<fast;
            return slow;
        }
    };