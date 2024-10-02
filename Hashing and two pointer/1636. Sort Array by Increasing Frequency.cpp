
// First stopring the key and freq of it
// Store it in a vector ot sort it using the different condition

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        vector<pair<int,int>> v;
        for(auto it: mpp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end() , [&](pair<int,int> &a,pair<int,int> &b) -> bool {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });
        vector<int> result;
        for(auto it : v) {
            for(int i=0;i<it.second;i++) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};


// Sort the vector accroding to the given condition

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        sort(nums.begin(),nums.end() , [&](int &a, int &b) -> bool {
            return mpp[a]==mpp[b] ? a > b : (mpp[a] < mpp[b]);
        });
        return nums;
    }
};

//