// Simple Approach
// Just use hash map to keep track of number of unique character in window
// Upon incerase in unique charcaters mroe tah required, Trim down the window
// If unique characters reaches threshold store the maxlength of substring

// However the below code complexity is
// T.C = O(N) + O(n) + O(log 256)

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int Longest_Subarray(string s, int k) {
    // your code here
    int i=0,j=0;
    map<char,int> mpp;
    int maxLen=-1;
    while(j<s.length()){
        mpp[s[j]]++;
        if(mpp.size()==k){
            maxLen = max(maxLen,j-i+1);
        }
        else if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return maxLen;
    }
};

// Optimization can be done still
// No need to trimd own the window size
// Just continue tracking the next character
// If the unique character is more than the required, Then remove the ith element and increment ith value
// Again traverse the next character, If again the requirement is more again remove the ith element and increment ith value


// Optimized Code 

// T.C = O(n) + O(log 256)


class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int i=0,j=0;
    map<char,int> mpp;
    int maxLen=-1;
    while(j<s.length()){
        mpp[s[j]]++;
        if(mpp.size()==k){
            maxLen = max(maxLen,j-i+1);
        }
        // Modification
        // "if" instead of "while"
        else if(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0)
            mpp.erase(s[i]);
            i++;
            }
        j++;
    }
    return maxLen;
    }
};