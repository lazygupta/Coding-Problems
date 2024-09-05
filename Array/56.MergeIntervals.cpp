// Brute Force cum best Approach

// We skip pushing when last pushed is smaller or equal

// T.C = O(N*logN) + O(2*N)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        
        for(i=0;i<n;i+=1){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!output.empty() && end <= output.back()[1]) continue;

            for(int j=i+1;j<n;j++){
                if(end >= intervals[j][0]){
                    end = max(end, intervals[j][1]);
                }
                else break;
            }
            output.push_back({start,end});
        }
        return output;
    }
};

// Optimal Approach

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        
        for(i=0;i<n;i+=1){

            if(output.empty() || intervals[i][0] > output.back()[1]){
                output.push_back(intervals[i]);
            }
            else{
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            }
        }
        return output;
    }
};