// In this question we have to return the count of good numbers of n digits

// First m is given, the no. of digits of a number

// Suppose n=5

// We have 5 places to fill the digit
// ___ ___ ___ ___ ___
//  E   O   E   O   E
// Even places are = 3
// Odd places are =2

// Good numbers must satisfy:- 
// 1. Even digits at even places
// 2. Prime digits at odd places
// Even idigits in 0-9 are = 0 2 4 6 8
// Prime digits in 0-9 are = 2 3 5 7

// So to fill the places we have atmost how many choice??
// For even position = 5
// For odd position = 4

// So all together the choices are
// 5 4 5 4 5 = 5*4*5*4*5 = 2000

// Lets take smaller example
// n=2
// ____ ____
//  E    O
//  5    4  = 5*4 = 20 numbers :- 0 2 4 6 8 ... ..... . . . . . .. ...63....85....87....

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

class Solution {
public:

    ll solve(ll x,ll even){
        if(even==0) return 1;
        ll ans=solve(x,even/2);
        ans*=ans;ans%=mod;
        if(even%2) ans*=x;
        ans%=mod;
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll oddplaces = n/2;
        ll evenplaces = n/2 + n%2;
        return (solve(5,evenplaces) * solve(4,oddplaces))%mod;
    }
};