#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int d=INT_MAX, start=0;
        for(auto x:t){
            mpp[x]++;
        }
        int i=0,j=0;
        int count=mpp.size();
        while(j<s.length()){
            if(mpp.find(s[j]) != mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0){
                    count--;
                }
            }
            if(count==0){
                while(count==0){
                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]]==1){
                            count++;
                            if(j-i+1<d){
                                d=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
            
        }
        return d==INT_MAX ? "" : s.substr(start,d);
    }
};