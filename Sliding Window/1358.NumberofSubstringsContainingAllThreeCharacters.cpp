// Check for pre sliding windows when coming to end of post
// If we check what is the minimal index where the condition of abc is satisfying
// Then we can add all the previous number of alphabets before that minimal index , to the answer

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {-1,-1,-1};
        int count=0,j=0;
        while(j<s.length()){
            freq[s[j]-'a'] = j;
            int minIndex = min(min(freq[0],freq[1]),freq[2]);
            if(freq[0]!=-1 && freq[1]!=-1  && freq[2]!=-1 ){
                count += 1 + minIndex;
                
            }
            j++;
        }
        return count;
    }
};