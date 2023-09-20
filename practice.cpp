// Input: nums = [5,10,1,5,2], k = 1
// Output: 13

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int count=0,sum=0;
        int arr[nums.size()];
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(__builtin_popcount(i)==k){
                arr[j]=i;
                j++;
            }   
        }
        for(int i=0;i<j;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<j;i++){
            sum+=nums[arr[i]];
        }

        return sum;
    }
};

int main(){
    vector<int> v{5,10,1,5,2};
    int k=1;
    Solution obj;
    cout<<obj.sumIndicesWithKSetBits(v,k);
    return 0;
}