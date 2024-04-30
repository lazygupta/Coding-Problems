#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string v) {
        {
        int i=0,j=0;
        int sum=0,mx=0;
        map<char,int> mpp;
        while(j<v.length()){
            mpp[v[j]]++;

            if(mpp.size()==j-i+1){
                mx = max ( mx, j-i+1);
                j++;
            }

            else if(mpp.size()<j-i+1){
                while(mpp.size()<j-i+1){
                    mpp[v[i]]--;
                    if(mpp[v[i]]==0)
                    mpp.erase(v[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
    }
};


// Another Solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int> mpp;
        int maxLength = 0;
        while(j<s.length()){ 
            if(mpp.find(s[j]) != mpp.end() && mpp[s[j]] >= i ){ // Check everytime that the current map value is greater than the first pointer
                i = mpp[s[j]] + 1; 
            }
            int len = j-i+1; 
            maxLength = max(maxLength,len);
            cout<<maxLength<<" "<<endl;
            mpp[s[j]] = j; 
            j++;
        }
        return maxLength;
    }
};