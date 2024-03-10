// The intuition behind is that to track the number of maximum and minimum possible open or close brackets


// (*))
// In above example 
// openmin = 1
// openmax = 2
// Now there is two closing bracket
// The 1st closing bracket will decrement the openmin = 0 and openmax = 1
// The 2nd closing bracket will decrement the openmin = -1 and openmax = 0
// And everytime openmin becomes negative we just reset its value to 0
// Now we will check that leftmin should be zero and leftmax shouldnt be negative

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int openmin=0,openmax=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                openmin++;
                openmax++;
            }
            else if(s[i] == ')'){
                openmin--;
                openmax--;
            }
            else{
                openmin--;
                openmax++;
            }
            if(openmin<0) openmin=0;
            if(openmax<0) return false;
        }
        return openmin==0;
    }
};
