// First we start counting the scores for the substring whose scoes is greater
// After that we go for 2nd substring

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string large,small;
        int lar_score = 0;
        int small_score = 0;
        if(y > x){
            lar_score = y;
            large = "ba";
            small_score = x;
            small = "ab";
        }
        else{
            lar_score = x;
            large = "ab";
            small_score = y;
            small = "ba";
        }

        vector<char> st;
        for(char ch:s){
            if(ch == large[1] && !st.empty() && st.back() == large[0]){
                score += lar_score;
                st.pop_back();
            }
            else st.push_back(ch);
        }
        vector<char> st1;
        for(char ch:st){
            if(ch == small[1] && !st1.empty() && st1.back() == small[0]){
                score += small_score;
                st1.pop_back();
            }
            else st1.push_back(ch);
        }
        return score;
    }
};