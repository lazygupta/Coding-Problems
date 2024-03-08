// In the following questions we dont just have to assign cookies to all the children
// We just have to try that maximum children should get cookies
// So we should start from the children having small greed factor


// First of all we should sort the greed factor of the children
// And thens ort the cookies sizes too
// So that the children with less greed factor can get minimum size cookie

// T.C = O(nlogn + mlogm) + O(n+m)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};