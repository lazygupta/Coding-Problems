// Let n=7
// (7) = (0111)
// (6) = (0110)
// 7 & 6 = 0111 & 0110 = 0110 > 0 i.e whenever the number and its predecessor number is bitwise and and it gives
// result>0 , the number is not power of 2

// Let n=8
// 8 = 1000
// 7 = 0111
// 8 & 7 = 0000 ==> 0 i.e whenever the number and its predecessor number is biwise & and it gives
// result=0 , the number is power of 2


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n & (n - 1)) return false;
        return true;
    }
};