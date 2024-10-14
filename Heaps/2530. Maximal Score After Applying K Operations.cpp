// T.C = O(NlogN)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> maxH;
        for(auto it: nums){
            maxH.push(it);
        }
        long long score = 0;
        for(int i=0;i<k;i++){
            score += maxH.top();
            double ceilele = maxH.top()/3.0;
            maxH.pop();
            maxH.push(ceil(ceilele));
        }
        return score;
    }
};