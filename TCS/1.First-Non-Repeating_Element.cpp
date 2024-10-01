// Using hashing

class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        map<int,int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        for(auto it: arr){
            if(mpp[it] == 1){
                return it;
            }
        }
        return 0;
    }
};

// Using unordered map 

// To optimize the code for better performance, consider using an unordered map instead of a map. The unordered map provides constant time complexity for average case lookups, which can improve the overall performance of the solution. This change can help reduce the time complexity of the code while maintaining the expected auxiliary space complexity.

// Remember that unordered maps have similar functionality to maps but offer faster lookups due to their hashing mechanism.