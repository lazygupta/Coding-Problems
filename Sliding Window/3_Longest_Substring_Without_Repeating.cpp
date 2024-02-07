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


int main(){
    int n=7;
    //17 15
    string str="pwwkew";
    int k=3;
    Solution ob;
    int v1=ob.lengthOfLongestSubstring(str);
    cout<<v1;
    return 0;
}