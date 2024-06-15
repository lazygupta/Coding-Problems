// This problem was labeled as hard but it is very simple if you understand what exactly to do
// So basically you have to first sort your projects according to the ascending capitals


// We have to start with the first project which will be surely be having minimum capital investment <= currentCapital
// So we will store the profit in a priorityQueue and will iterate over next project again check for capitalInvestment <= currenCapital

// if at first iteration nothing is in priority queue it means that we were not having initialCapital to start any projects

// Everytuime increase your currentCapital by profit you made with the project in the priority queue
// remove everytime from priority qyueue the profit

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int i = 0;
        vector<pair<int,int>> projects;
        for(int i=0;i<profits.size();i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int> maximizedProfit;
        int currCapital = w;
        while(k--){
            while(i<profits.size() && projects[i].first <= currCapital){
                maximizedProfit.push(projects[i].second);
                i++;
            }
            if(maximizedProfit.empty()) break;
            currCapital += maximizedProfit.top();
            maximizedProfit.pop();
        }
        return currCapital;
    }
};