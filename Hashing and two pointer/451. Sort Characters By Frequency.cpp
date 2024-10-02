// Append functionality used
// It adds a character no, of times stated in the oparamters

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        vector<string> bucket(s.size()+1, "");
        string res="";
        for(auto it:s) mpp[it]++;
        for(auto it:mpp){
            int i = it.second;
            char character = it.first;
            bucket[i].append(i,character);
        }
        for(int i=s.size(); i>=0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};