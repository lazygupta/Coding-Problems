

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((nums[i]*nums[j])%k==0){
                    count++;
                }
            }
        }

        return count;
    }
};

int main(){

    vector<int> v{4,3,56,7,78,8,75,34};
    int k =5;

    Solution obj;

    cout<<obj.countPairs(v, k);

}