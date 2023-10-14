// Approach is to be decrease the comparision between all the strings
// present in the vector
// Because that would increase our complexity

// So we will sort our vector's string lexicographically which will take O(NlogN)

// So our comparision decrease to only two stringa
// The first and the last string would be having most different prefix or common characters


// e.g "flower","flow","flight"
// Upon sorting we get --->  "flight" "flow" "flower"

// Now comparing the first and last it is having most common characters

// T.C = O(NlogN)
// S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        int n = strs.size();
        sort(strs.begin(),strs.end());
        int i=0;
        string first = strs[0] , last = strs[n-1] ;
        int length = min (first.length(),last.length());
        while(i<length){
            if(first[i] != last[i]){
                return res;
            }
            res += first[i];
            i++;
        }
        return res;
    }
};