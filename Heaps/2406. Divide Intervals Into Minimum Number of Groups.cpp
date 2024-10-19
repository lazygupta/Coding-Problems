//  Maintain a min heap of right individuals of each groups
// If the left of any group is greater than heap ele, Then pop the heap and push the new right of that group
// If its not the case simply push the right ele of the group


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int> , greater<int>> pq;
        for(auto it: intervals){
            int left = it[0];
            int right = it[1];
            if(!pq.empty() && pq.top() < left) {
                pq.pop();
                pq.push(right);
            } else {
                pq.push(right);
            }
        }
        return pq.size();
    }
};