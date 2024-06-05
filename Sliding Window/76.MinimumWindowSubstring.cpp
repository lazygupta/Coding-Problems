// Just keep a hashmap ready or pre inserted with the charcaters in string t
// traverse over string s
// If the character in string s in positive in hashmap, It means it is pre inserted and we increase the count,
// and decerease the freq of character, so that next time we can check it is positive or not
// Upon reaching count==string t size , start shrinking the window and storing the window size at each point
// Along with the storing size, store the starting index too i.e., starting index of a window

// T.C = O(2N) + O(M)

// S.C = O(256)


class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;
        map<char, int> mpp;
        for (auto it : t) {
            mpp[it]++;
        }
        int minLength = INT_MAX;
        int start = 0;
        int count = 0;
        while (j < s.size()) {
            if (mpp[s[j]] > 0) { 
                count++;
            }
            mpp[s[j]]--;
            while (count == t.size()) {
                mpp[s[i]]++;
                if (mpp[s[i]] > 0) {
                    count--;
                    if (minLength > j - i + 1) {
                        start = i;
                        minLength = j - i + 1;
                    }
                }
                i++;
            }

            j++;
        }
        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};