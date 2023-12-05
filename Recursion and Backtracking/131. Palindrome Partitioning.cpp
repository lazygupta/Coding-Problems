// Time Complexity: O( (2^n) *k*(n/2) )

// Space Complexity: O(k * x)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPallindrome(string str,int start,int end){
        while(start<=end){
            if(str[start++]!=str[end--]){
                return false;
            }
        }
        return true;
    }

    void find(int index,vector<vector<string>> &res,vector<string> bucket,string s){
        if(index >= s.length()){
            res.push_back(bucket);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(isPallindrome(s,index,i)){
                bucket.push_back(s.substr(index,i-index+1));
                find(i+1,res,bucket,s);
                bucket.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> bucket;
        find(0,res,bucket,s);
        return res;
    }
};