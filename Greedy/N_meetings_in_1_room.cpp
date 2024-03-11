// Greedy Approach - We should start the meeting which ends early
// So we sort the array according to the ending time in ascending order

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int,int>> vec;
    for (int i = 0; i < start.size(); i++) {
        vec.push_back({end[i],start[i]});
    }
    sort(vec.begin(), vec.end());
    int limit = vec[0].first;
    int temp=1;
    for(int i=1;i<start.size();i++){
        if(vec[i].second > limit){
            temp++;
            limit =vec[i].first;
        }
    }
    return temp;
}