// First read the questions

// Do kaam karna hai
// First score badhane ka kosis krna hai power gawa ke
// Fir score agar hai toh power badhane ka kosis krna hai score gawa ke

// Then ban gaya question

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        //100,200
        int start=0,end=tokens.size()-1;
        int score=0,max_score=0;
        while(start <= end){
            if(power >= tokens[start]){
                power-=tokens[start++];// I decreased my power to increase my score
                max_score = max(max_score,++score); // Storing my till now obtained max score
            }
            else if(score>0){
                score--; // I decreased my score to increase my power to max hence choosing the maximum token value
                power += tokens[end--]; // Increasing my power to maximum token value till now 
            }
            else{
                break;
            }
        }
        return max_score;
    }
};