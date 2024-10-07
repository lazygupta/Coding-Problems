// Maintain min heap
// Extract from top and stroe it in res vector 
// Eveyrtime the min heap top ele get pop out
// min heap maintain its fashion automatically

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> res;
        priority_queue<int , vector<int> , greater<int>> minH;
        for(auto it: arr){
            for(auto it1: it){
                minH.push(it1);
            }
        }
        while(!minH.empty()){
            res.push_back(minH.top());
            minH.pop();
        }
        return res;
    }
};