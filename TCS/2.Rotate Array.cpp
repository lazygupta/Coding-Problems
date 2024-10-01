// Simple implementation

class Solution {
public:

    void func(vector<int> &nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        func(nums,0,n-k-1);
        func(nums,n-k,n-1);
        func(nums,0,n-1);
    }
};