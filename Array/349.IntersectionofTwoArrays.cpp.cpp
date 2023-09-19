// 

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

  vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
    unordered_set<int> m{nums1.begin(),nums1.end()};
    vector<int> res;
    for(auto x:nums2){
      if(find(m.begin(),m.end(),x) != m.end()){
        res.push_back(x);
        m.erase(x);
      }
    }
    return res;
  }
};