// Make the most expensive cut as early as possible, which leads to a greedy solution.
// The order of horizontalCut and verticalCut doesn't matter, so we can sort them.

// Sort cuts
// Make the most expensive cut, and cut the slice into 1 * 1 cakes.
// Repeat this.

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Greedy Approach

        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        int verticalBlocks = 1;
        int horizontalBlocks = 1;
        int i=0,j=0;
        int cost =0;
        while(i<m-1 && j<n-1){
            if(horizontalCut[i] > verticalCut[j]){
                cost += horizontalCut[i] * verticalBlocks;
                horizontalBlocks++;
                i++;
            }
            else{
                cost += verticalCut[j] * horizontalBlocks;
                verticalBlocks++;
                j++;
            }
        }
        while(i<m-1){
            cost+= horizontalCut[i] * verticalBlocks;
            i++;
        }
        while(j<n-1){
            cost+= verticalCut[j] * horizontalBlocks;
            j++;
        }
        return cost;
    }
};