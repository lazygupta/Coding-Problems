// Better Approach

// Using Hashing

// T.C = O ( N )
// S.C = O(N) + O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int , int> mpp;
        vector<int> v;
        int mini = (int)nums.size()/3 +1 ;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if (mpp[nums[i]] == mini) {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};

// Optimal Approach
class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int cnt1=0,cnt2=0;
        int el1=0;
        int el2=0;
        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];//2
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];//1
        }
        else if (v[i] == el1) cnt1++;
        else if (v[i] == el2) cnt2++;//2
        else {
            cnt1--, cnt2--;//0 1//
        }
    }
        cout<<el1<<" "<<el2;
        cnt1=0;cnt2=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==el1) cnt1++;
            else if(v[i]==el2) cnt2++;
        }
        int mini= (int)(v.size()/3);

        if(cnt1 > mini) res.push_back(el1);
        if(cnt2 > mini) res.push_back(el2);

        return res;
    }
};
// 