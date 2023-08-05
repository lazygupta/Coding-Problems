// We are just calculating the coins needed for each row
// And then decreasing the total number of coins

// T = O(N) 
// S = O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int cost=0,count=0;
        for(int i=0;i<=n;i++){
            cost = i+1;
            n=n-cost;
            if(n<0){
                break;
            }
            else count++;
        }
        return count;
    }
};

// Just think, just solve the quadratic equation: (K * (K+1))/2 <= N 
// at last we will get: K <= sqrt(2N + 1/4) - 1/2

// 1st row we need '1' coin, 2nd coin -> 2, 3rd coin -> 3 and so on.
// so if there is 'k' rows then total number of coins used in making 'k' rows must be less than 'n'.
// i.e K <= (K * (K+1))/2 <= N


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int rows=0,count=0;
        // (k*k+1) /2 <= n
        rows= sqrt((2*(long)n)+(0.25)) - (0.5);
        return int(rows);
    }
};


// Now we can think of Binary Search

// Best
// using binary search

// number of coins required for the kth row will be equal to 1 + 2 + 3 + ... + k = k * (k + 1) / 2.

// T = O(log N)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        long start = 1;
        long end = n ;
        while (start <= end) {
            long row = start + (end - start) / 2;
            long coinsFilled = row * (row + 1) / 2;
            if (coinsFilled <= n) {
                start = row + 1;
            } else {
                end = row - 1;
            }
        }
        return end;
    }
};

