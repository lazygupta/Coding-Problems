// Memoization approach
// Simple taking and not taking problem

class Solution{   
public:

    bool func(vector<vector<int>> &dp,vector<int> &arr, int target,int index){
        if(target == 0){
            return true;
        }
        if(index == 0){
            return arr[0] == target;
        }
        if(dp[index][target] != -1) return dp[index][target];
        bool notTaken = func(dp,arr,target,index-1);
        bool taken = false;
        if(arr[index] <= target) taken = func(dp,arr,target-arr[index],index-1);
        return dp[index][target] = taken || notTaken;
    }

    bool isSubsetSum(vector<int>arr, int k){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (k+1,-1)); // Index can be anything between 0 and arr.size // And taregt can be anything between 0 and k
        return func(dp,arr,k,n-1);
    }
};

// Tabulation Approach


class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int k){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool> (k+1,false));
        // Tabulation Approach
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(arr[0] <= k){
            dp[0][arr[0]] = true; // This is just done to mark arr[0] as target at 0 index as true
        }
        for(int i = 1;i<n;i++){
            for(int target = 1;target<=k;target++){
                // If we not take anything then result will be same
                bool notTaken = dp[i-1][target];
                bool taken = false;
                if(arr[i] <= target){
                    taken = dp[i-1][target-arr[i]];
                }
                dp[i][target] = taken || notTaken;
            }
        }
        return dp[n-1][k];
    }
};