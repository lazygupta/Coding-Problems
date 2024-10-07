// Using priority Queue
// It does sorting in max heap fashion
// T.C = O(nlogn)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it: nums){
            pq.push(it);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

// It also does the same work,
// But here we are maintaining min heap, and till the size of required k only
// Why to store the element greater than k if we have to do work with only k
// So for min heap the top element will be the 
// kth largest or(n-k)th smallest


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto it: nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};