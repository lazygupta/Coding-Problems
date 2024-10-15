// Memoization approach 
// Same as Subset Sum problem

// First we have to check that sum is odd or even
// If the sum is even then only the array can be divided into two equal sum
// And if its odd it can never be partirtioned into equal sum


// Time Complexity: O(N*K) + O(N)
// Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

// Space Complexity: O(N*K) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).

class Solution {
public:
int functionEntered=0;
    bool func(vector<int> &nums,int index,int target,vector<vector<int>> &dp){
        functionEntered++;
        if(target == 0){
            return true;
        }
        if (index == 0) {
            return nums[0] == target;
        }
        if(dp[index][target] != -1) return dp[index][target];
        bool notTaken = func(nums,index-1,target,dp);
        bool taken = false;
        if(nums[index] <= target) taken = func(nums,index-1,target-nums[index],dp);
        return dp[index][target] = taken || notTaken;
    }

    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 == 1) return false;
        int n = nums.size();
        int k = sum/2;
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        bool res = func(nums,n-1,k,dp);
        cout<<functionEntered<<endl;
        return res;
    }
};

// Tabulation Approach
// Optimising Space due to recursions tack space


// Time Complexity: O(N*K) +O(N)
// Reason: There are two nested loops that account for O(N*K) and at starting we are running a for loop to calculate totSum.

// Space Complexity: O(N*K)
// Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.

class Solution {
public:
// Tabulation
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int n = nums.size();
        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= k) {
            dp[0][nums[0]] = true;
        }
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (nums[index] <= target)
                    taken = dp[index - 1][target - nums[index]];
                dp[index][target] = taken || notTaken;
            }
        }
        return dp[n-1][k];
    }
};