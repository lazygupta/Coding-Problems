// discards all leading whitespaces
// sign of the number
// overflow
// invalid input

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign=1;long long int ans=0,i=0;
        while(s[i] == ' '){
            i++;
            continue;
        }
        if(s[i] == '-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            ans=ans*10+(s[i]-'0');
            if(sign==-1){
                if(sign*ans<INT_MIN) return INT_MIN;
            }
            else{
                if(ans>INT_MAX) return INT_MAX;
            }
            i++;
        }
        if(sign==-1){
            return sign*ans;
        }
        else{
            return ans;
        }
    }
};