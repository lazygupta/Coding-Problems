// Check everytime that when the customer arrives then the prev_finish time is smaller than that or not


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double wait_time = customers[0][1];
        double prev_finish = customers[0][1] + customers[0][0];
        for(int i=1; i<n ;i++){
            auto it = customers[i];
            double arrival_time = it[0];
            double start_time = max(arrival_time,prev_finish);
            double end_time = start_time + it[1];
            prev_finish = end_time;
            wait_time += (end_time - arrival_time);
        }
        return (double)wait_time/n;
    }
};