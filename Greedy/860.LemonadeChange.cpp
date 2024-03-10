// The greedy idea here is that we use large coins to change as much as possible so as to leave more small coins in our hands.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        if(bills[0] != 5) return false;
        for(int i=0;i<bills.size();i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                five--;
                ten++;
            }
            else if(ten>0){
                ten--; five--;
            }
            else {
                five -= 3;
            }
            if(five<0) return false;
        }
        return (five>=0 && ten>=0)?true:false;
    }
};