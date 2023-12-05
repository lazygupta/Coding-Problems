#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void find(int index,vector<string> &res,string &bucket, string digits,string pattern[]){
        
        if(index >= digits.length()){
            res.push_back(bucket);
            return;
        }

        int number = digits[index] - '0';
        string value = pattern[number];

        for(int i=0; i<value.length(); i++){
            bucket.push_back(value[i]);//bucket.push_back(pattern[number][i])
            find(index+1,res,bucket,digits,pattern);
            bucket.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string bucket;
        if(digits.length()==0){
            return res;
        }
        string pattern[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        find(index,res,bucket,digits,pattern);
        return res;
    }
};