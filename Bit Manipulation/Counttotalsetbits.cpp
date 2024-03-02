// Using recursion
// T.C = O(logN)

// Calculate the no. of bits first from 0 to 2^x by using formula = x.2^(x-1)
// Calculate the no. of bits from 2^x to n by using formula = n - 2^x + 1
// Then the rest one by rescursion

// 0 -> 0 0 0 0 ------
// 1 -> 0 0 0 1      |
// 2 -> 0 0 1 0      |
// 3 -> 0 0 1 1      |   1st calculation => 2^(3-1) * 3 = 2^2*3 = 12
// 4 -> 0 1 0 0      |
// 5 -> 0 1 0 1      |
// 6 -> 0 1 1 0      |
// 7 -> 0 1 1 1 ------
// 8 -> 1 0 0 0 ------
// 9 -> 1 0 0 1      |
// 10 -> 1 0 1 0     | 2nd calculation of msb = n-2^x+1 = 12 - 8 + 1 = 5
// 11 -> 1 0 1 1     |
// 12 -> 1 1 0 0 -----

// After that again we have to calculate bits for 8 to 12 excluding msb
// Calculate the rest and recursively iterate it => 2^(2-1) * 2 = 4
// Again calculate the rest that is in 12 how many bits => 1
// total = 12+5+4+1 = 22

#include<bits/stdc++.h>
using namespace std;

int lengthofbits(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }

int solution(int n){
    if(n==0) return 0;
    int x = lengthofbits(n);
    int till2x = (1<<(x-1)) * x;
    int msb2xton = n - (1<<x) +1;
    int rest = n - (1<<x);
    return till2x + msb2xton + solution(rest);
}

int countSetBits(int N)
{
    return solution(N);
}