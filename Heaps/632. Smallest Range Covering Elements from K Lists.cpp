// Most impressive question

// Heap
// Think of mainataining minheap of every group 

// And choose a minimuim from heap nad maxValue from group

// We simply have to increase the minimum to larger value and maxValue will be adjuisted auto,atically
// this is done just to decrease the difference between range

typedef vector<int> vi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< vi , vector<vi> , greater<vi> > heap;
        int maxVal = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            heap.push({nums[i][0] , i , 0});
            maxVal = max(nums[i][0] , maxVal);
        }
        int start = 0, end = INT_MAX;
        while(heap.size() == nums.size() ){
            auto top = heap.top(); // This will make sure we are always taking minimum of all the groups
            int minVal = top[0];
            int row = top[1];
            int col = top[2];
            heap.pop();

            if(maxVal - minVal < end - start){
                end = maxVal;
                start = minVal;
            }

            if(col + 1 < nums[row].size()){ // Checking the nextvalue of that same group cuz at everyminimum we have to increase the minimum to larger value
                int nextValSameGroup = nums[row][col+1];
                heap.push({nextValSameGroup, row, col+1});
                maxVal = max(maxVal,nextValSameGroup);
            }
        }
        return {start,end};
    }
};