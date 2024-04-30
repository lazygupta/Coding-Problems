// Use sliding window in same method

// First store first character freq and then check the after entry of next element
// Do the characetr need to change to uppercase character in order to make them equal
// If the character needed to change will be greater than k , Then start sliding window to right
// Decrement the left pointer value and update the maximum fequency of the mapped value till now
// Check if tha changes needed is not greate than k, Then we can store the length and maxLength

// T. C  = (N+N) * 26

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxLength = 0;
        map<char,int> mpp;
        int max_freq = 0;
        while(j<s.length()){
            mpp[s[j]]++;
            max_freq = max( max_freq, mpp[s[j]]);
            if( (j-i+1)- max_freq > k){
                mpp[s[i]]--;
                max_freq=0;
                for(auto it:mpp){
                    max_freq = max(max_freq,it.second);
                }
                i++;
            }
            int len = j-i+1;
            maxLength = max(len,maxLength);
            j++;
        }
        return maxLength;
    }
};