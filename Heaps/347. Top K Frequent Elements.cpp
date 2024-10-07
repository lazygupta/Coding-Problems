// First store the freq of the element
// Then according to the frequency
// Add the ele to minHeap and add the condition
// so that heap size should not be more than k

typedef pair<int,int> pi;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        priority_queue<pi,vector<pi>,greater<pi>> minH;
        for(auto it: mpp){
            minH.push({it.second,it.first});
            if(minH.size()>k) minH.pop();
        }
        vector<int> res;
        while(!minH.empty() && res.size()<k){
            res.push_back(minH.top().second);
            minH.pop();
        }
        return res;
    }
};