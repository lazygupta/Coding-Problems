// At first it seems to be hard
// Dont think about making two seperate array

// Insrtead focus on how can we get minimum difference
// If we sort an array , and partition it into two equal parts
// So the max of first part and min of second part will give the smallest differecne always

class Solution {
    public:
        int findValueOfPartition(vector<int>& nums) {
            int n = nums.size();
            int mid = n/2;
            sort(nums.begin(),nums.end());
            return abs(nums[n/2-1] - nums[n/2]);
        }
};

// But above solution fails whent eh arrays has duplicates
// e.g [84,11,100,100,75]
// The answer will be [11,84] and [75,100,100] => |84-75| = 9 ❌ which is wrong
// the correct answer will be |100-100|

// So, best solution

// Finding difference f each and every consecutive element and stroing the minimum of all

class Solution {
    public:
        int findValueOfPartition(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int minimum = INT_MAX;
            for(int i = 1;i<nums.size();i++){
              minimum = min(minimum, nums[i]-nums[i-1]);
            }
            return minimum;
        }
};