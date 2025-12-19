#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        int ans;
        int steps = 0;
        while(!q.empty()){
            string word = q.front().first;
            steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++){
                int original = word[i];
                for(char c='a'; c<='z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

// TC =  O(N * L * 26)
// SC = O(N * L)