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

// 2nd Method
// Recursion Way

// Implement recursion carefully, its very easy


typedef long long int ll;
class Solution {
public:

    ll helper(string s,int sign, int index,ll res){
        if(sign*res >= INT_MAX) return INT_MAX;
        if(sign*res <= INT_MIN) return INT_MIN;

        if(index >= s.size() || s[index] < '0' || s[index]> '9' ){
            return sign*res;
        }
        res = helper(s,sign,index+1,res*10+(s[index]-'0'));
        return res;
    }

    int myAtoi(string s) {
        int index = 0,sign = 1;
        while(index<s.length() && s[index] == ' ') index++;
        if(s[index] == '-'){
            sign = -1;
            index++;
        }
        else if(s[index] == '+'){
            index++;
        }
        return helper(s,sign,index,0);
    }
};