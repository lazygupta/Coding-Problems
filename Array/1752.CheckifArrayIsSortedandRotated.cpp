// Brute solution

// O(n+n)

class Solution {
public:
    bool check(vector<int>& nums) {
        int index = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                index = i+1;
                break;
            }
        }
        int n = nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if((nums[(i+index) % n]) > nums[(i+index+1) % n]){
                return false;
            }
        }
        return true;
    }
};

// Optimal


// just check that at any time the element is not greater than next element at most once

class Solution {
public:
    bool check(vector<int>& nums) {
        int count_greater=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i%nums.size()] > nums[(i+1)%nums.size()]){
                count_greater++;
            }
        }
        return count_greater<=1;
    }
};