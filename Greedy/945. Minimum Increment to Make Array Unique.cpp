// just check that what is the needed value in next traversal
// If neededValue - currentValue is more than 0
// count increases to neededValue-currentValue;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int neededValue = 0;
        for(int i=0;i<nums.size();i++){
            if(neededValue - nums[i] > 0){ // neededValue - currValue
                count += neededValue-nums[i];
            }
            neededValue = max(nums[i],neededValue)+1;
        }
        return count;
    }
};