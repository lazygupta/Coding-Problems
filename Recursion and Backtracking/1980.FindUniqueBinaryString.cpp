// Just like generating all binary strings and then printing any one of them which is not there already

typedef long long int ll;
class Solution {
public:

    void generateBinaryString(int size,string res,ll length,vector<string> &bucket){
        if(length == size){
            bucket.push_back(res);
            return;
        }
        res.push_back('0');
        generateBinaryString(size,res,length+1,bucket);
        res.pop_back();
        res.push_back('1');
        generateBinaryString(size,res,length+1,bucket);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<string> bucket;
        generateBinaryString(nums[0].size(),"",0,bucket);
        for(int i=0;i<bucket.size();i++){
            if(find(nums.begin(),nums.end(),bucket[i]) == nums.end())
                return bucket[i];
        }
        return "-1";
    }
};