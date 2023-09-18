// Brute Force Solution

// T.C = O(max(v[i]) * n) 
// The code will be having timer limit exceeded error
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:

    int maximum(vector<int> &v){
        int maximum=0;
        for(int i=0;i<v.size();i++){
            maximum = max (v[i], maximum);
        }
        return maximum;
    }

    ll result(vector<int> &v,int hour_speed){
        ll totalhrstaken=0;
        for(int i=0;i<v.size();i++){
            totalhrstaken += ceil(double(v[i])/double(hour_speed));
        }
        return totalhrstaken;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll reqhrs=0;
        for(int i=1;i<=maximum(piles);i++){
            reqhrs=result(piles,i);
            if(reqhrs<=h){
                return i;
            }
        }
        return 0;
    }
};

//Think of Binary Search

// We have a answer from 1 to maximum no. of elements in array

// Therefore we can think of the binary search

// T.C = O(max(elements) * logN)

#define ll long long

class Solution
{
public:
    int maximum(vector<int> &v)
    {
        int maximum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            maximum = max(v[i], maximum);
        }
        return maximum;
    }

    ll result(vector<int> &v, int hour_speed)
    {
        ll totalhrstaken = 0;
        for (int i = 0; i < v.size(); i++)
        {
            totalhrstaken += ceil(double(v[i]) / double(hour_speed));
        }
        return totalhrstaken;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = maximum(piles);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (result(piles, mid) > h)
            {
                low = mid + 1;
            }

            if (result(piles, mid) <= h)
            {
                high = mid - 1;
            }
        }
        return low;
    }
};