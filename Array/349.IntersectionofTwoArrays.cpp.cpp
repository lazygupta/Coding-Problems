// Revised 8 Dec
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

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