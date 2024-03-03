#include<bits/stdc++.h>
using namespace std;

int lengthofbits(int n){
        int x=0;
        while ((1 << x) <= n) {
          x++;
        }
        return x - 1;
}

int setBits(int n){
    int x = lengthofbits(n);
    // cout<<x<<endl;
    // cout<<(1<<(x+1))<<endl;
    int shift = (1<<(x+1)); //  For checking the numbers having only set bits
    if(n == (shift-1)) return n;
    int count= 0;
    int temp=n;
    while((temp%2)!=0){
        count++;
        temp=temp/2;
    }
    int bitmask = 1<<count; // 0001 | 00111
    return n|bitmask;
}