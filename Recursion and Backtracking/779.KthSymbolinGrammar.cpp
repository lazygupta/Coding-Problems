// We can observe one thing
// suppose n=4
// 0
// 01
// 0110
// 01101001
// 0110100110010110
// Now oberve one thing
// 0
// 0 1
// 0 1 10
// 0 1 1 0 1001

// In the coming next series, 
// Suppose n=3
// First 2^(n-1)/2 (or 2) elements are same as previous one
// And the remaining 2^(n-1)/2 (or 2) elements are complement of the previous

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }
        int mid = pow(2,n-1)/2;
        if(k<=mid){
            return kthGrammar(n-1,k);
        }
        else{
            return !kthGrammar(n-1,k-mid);
        }
        return 0;
    }
};