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