class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> prefix(n,arr[0]);
        vector<int> suffix(n,arr[n-1]);
        for(int i =1;i<n;i++){
            prefix[i] = prefix[i-1] + arr[i]; // Calculation the prefix sum for all element
        }
        for(int j=n-2;j>=0;j--){
            suffix[j] = suffix[j + 1] + arr[j]; // Calculate the suffix sum for all element
        }
        for(int i =0;i<n;i++){
            if(suffix[i] == prefix[i]){
                return "true";
            }
        }
        return "false";
    }
};


// Now we can space optimise it

class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0,right = 0;
        int i = 1;
        while(i<n){
            right += arr[i];
            i++;
        }
        int j = 1;
        while(j<n-1 && left!=right){
            left += arr[j-1];
            right -= arr[j];
            j++;
        }
        return left==right ? "true" : "false";
    }
};