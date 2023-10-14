// Just store theboth string character value 
// Check everytime the next character is mapped into correct posiiton

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256]={0},m2[256]={0};
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};