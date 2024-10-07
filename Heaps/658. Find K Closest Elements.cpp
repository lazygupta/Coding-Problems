// Builidng maxHeap but according to the absolute diffrence , 
// Why??
// Reason suppose arr = [1,2,3,4,5] and x = 3
// So closest to x will be which number,
// Simple, the difference of (arr[i]-x) 
// the more smaller the difference between two, the more closer it will be

// Now after maintaining maxheap
// We will now take another heap to sort according to the value
// Our question demands to thne resulting answer to be soprted


// T.c 
// maxheap - O(nlogk)
// popping out - O(klogk)
// sorting or building minheap again- (klogk)

// T.C = O(nlogK + KlogK)


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxH;
        for(int i=0;i<arr.size();i++){
            maxH.push({ abs(arr[i]-x) , arr[i]});
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        priority_queue<int, vector<int> , greater<int>> pq;
        while(!maxH.empty()){
            pq.push(maxH.top().second);
            maxH.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

// Another approach using only single priority queue


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxH;
        for(int i=0;i<arr.size();i++){
            maxH.push({ abs(arr[i]-x) , arr[i]});
            if(maxH.size() > k){
                maxH.pop();
            }
        }
        vector<int> res;
        while(!maxH.empty()){
            res.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};

