// same approach as N meetings in one room
// Just we have to sort the array according to the ending right pair in increasing
// Because the approach should be to start and end with the pair which ends first

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> vec;
        for(int i=0;i<pairs.size();i++){
            vec.push_back({pairs[i][1],pairs[i][0]});
        }
        sort(vec.begin(),vec.end());
        //[ (2,1) (5,4) (8,7) ]
        int limit = vec[0].first;
        int count=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i].second > limit){
                count++;
                limit = vec[i].first;
            }
        }
        return count;
    }
};