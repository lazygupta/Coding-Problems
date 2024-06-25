#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int l=0,r=0;
        vector<int> unionArr;
        while(l<n && r<m){
            if(arr1[l] <= arr2[r]){
                if(!unionArr.size() || unionArr.back()!=arr1[l]){
                    unionArr.push_back(arr1[l]);
                }
                l++;
            }
            else{
                if(!unionArr.size() || unionArr.back()!=arr2[r]){
                    unionArr.push_back(arr2[r]);
                }
                r++;
            }
        }
        while(l<n){
            if(unionArr.back()!=arr1[l]){
                    unionArr.push_back(arr1[l]);
                }
            l++;
        }
        while(r<m){
            if( unionArr.back()!=arr2[r]){
                    unionArr.push_back(arr2[r]);
                }
            r++;
        }
        return unionArr;
    }
};