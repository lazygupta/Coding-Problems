// Using strigstream class

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
            words.push_back(tmp);

        string ans;
        for (int i = words.size() - 1; i >= 0; --i) {
            if (i != words.size() - 1) ans += " ";
            ans += words[i];
        }
        return ans;
    }
};


// Optimal Approach 
// S.C = O(1)
class Solution {
public:
    string reverseWords(string s) {
        int i=0,l=0,r=0;
        reverse(s.begin(),s.end());
        while(i<s.length()){
            while( i<s.length() && s[i] != ' '){
                s[r++]=s[i++];
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};