// This can be done using map
// Approach:-
// Store the element with its freq in a map

// Now we can store those map value in a vector in order to sort it

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> v;
        map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), [](pair<char,int> &a,pair<char,int> &b) -> bool { 
            return a.second > b.second; 
        }); // Use of lambda expression
        
        string res = "";

        for(auto it: v){
            for(int i=0;i<it.second;i++){
                res.push_back(it.first);
            }
        }
        return res;
    }
};

// Maybe the above solution is having more time complexity
// Lets think of something like bucket where we store the character in the index equal to its frequency

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