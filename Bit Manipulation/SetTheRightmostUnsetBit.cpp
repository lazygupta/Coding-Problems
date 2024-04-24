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

// 2nd Approach - Bit Manipulation

class Solution{
    public:
    vector<long long int> twoOddNum(long long int nums[], long long int n)  
    {
        // code here
        int xxory = 0;
        for (int i = 0; i < n; ++i) {
            xxory ^= nums[i];
        }
        // Mask for rightmostset bit
        int mask = xxory & -(xxory-1); // To find out rightmostsetbit, this is a mask 
        long long int first=0,second=0;
        for(int i = 0; i < n; ++i){
            if(nums[i] & mask){
                first = first ^ nums[i]; // Yaha pr wo aayega jiska rightmostbit set hoga
            }
            else{
                second = second ^ nums[i];
            }
        }
        // cout<<endl;
        if(first>second){
            return {first,second};
        }
        else{
            return {second,first};
        }
    }
};