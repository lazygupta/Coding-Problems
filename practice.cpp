#include<bits/stdc++.h>
using namespace std;

void isIsomorphic(string s, string t) {
        map <char,char> mpp;
        if(s.length()!=t.length()) return;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])!=mpp.end())
            mpp[s[i]]=t[i];
        }
        for(auto it:mpp){
            cout<<it.first<<" "<<it.second;
        }
        // int count =0;
        // for(int i=0;i<s.length();i++){
        //     if(t[i] == mpp[s[i]])
        //     count++;
        // }
        // return count==s.length()?true:false;
}


int main(){
    string a="foo",b="bar";
    isIsomorphic(a,b);
    return 0;
}