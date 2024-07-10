// The question comprises of making choices, so the first algorithm that should be coming into our mind is Recrusion
// The question can be done using recursion tree
// But the comoplexity would be higher

// T.C = O(N^N)
// Time Limit exceeded

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return create(nums, 0); 
    }
private:
    bool create(vector<int>& nums, int idx) {
        if(idx == nums.size() -1) return true;  //if I reach the last index, I should return true;
        if(nums[idx] == 0) return false; //if at any  point I reach an index with jump value = 0
		//,I'll get stuck and hence will return a false.
        
        int reach = idx + nums[idx]; //the max jump that I can make
		//I can make jumps ranging from idx + 1, till reach, and hence will run a loop
		//to cover all those possbile jumps
        for(int jump=idx + 1; jump <= reach; jump++) {
		//if true, it means taking this jump led me to the last index.
            if(jump < nums.size() && create(nums, jump)) 
                return  true; 
        }
			
		//if I reach  here,  it means none of the jumps led  me to the  last index 
		//and hence returning, false.
        return  false;
    }
};

// Think of greedy approach

// Eg [2,3,1,1,4]
//             |
//             |
//            goal

// Now lets think of starting it from end 
// We will check everytime that the jump before goal is more than or equal to required jump
// if it is enough we will shift the goal to previous index
// Because if index 4 is reached through index 3, then the goal should be reaching index 3 first
// At last the goal should be at index 0
// So, If we can reach from end to start
// Then we can also reach from start to end

// Eg [2,3,1,1,4]
//             |
//             |
//            goal
// Eg [2,3,1,1,4]
//           |
//           |
//          goal
// Eg [2,3,1,1,4]
//         |
//         |
//        goal
// Eg [2,3,1,1,4]
//       |
//       |
//     goal
// Eg [2,3,1,1,4]
//     |
//     |
//   goal

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i=goal-1;i>=0;i--){
            if( i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal==0?true:false;
        // 3 2 1 0 4
    }
};