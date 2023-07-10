// Problem is also known as Sort an array containing 0s 1s and 2s

// Brute Force solution is O(NlogN) by using merge sort

// Better Force solution is O(N) + O(N) = O(2N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) cnt0++;
        if(arr[i]==1) cnt1++;
        if(arr[i]==2) cnt2++;
    }

    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }

    for(int i=cnt0;i<cnt0+cnt1;i++){
        arr[i]=1;
    }

    for(int i=cnt0+cnt1;i<arr.size();i++){
        arr[i]=2;
    }
    }
};

// So this problem is also known as Dutch National Flag Question

// As there are three colors red white and blue which represent Dutch Flag
// TC - O(N)
// SC - O(1)

// This algorithm really impressed me

// Click here to know about algorithm https://drive.google.com/file/d/1V67tC_jQuVA1iR1RlIKhh_pDeTHorhiX/view?usp=sharing


class Solution {
public:
    void sortColors(vector<int>& arr) {
    int low=0,mid=0;
    int high= arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid]==1) mid++;

        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    }
};