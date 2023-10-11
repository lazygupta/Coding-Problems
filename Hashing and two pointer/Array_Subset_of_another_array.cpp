// Hashing technique

// Arr 1 should contain all the elemnbts of arr 2

#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    map<int , int> mpp;
    
    for(int i=0;i<n;i++){
        mpp[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(mpp.find(a2[i]) != mpp.end()){
            mpp[a2[i]]--;
            if(mpp[a2[i]]==0){
                mpp.erase(a2[i]);
            }
        }
        else if(mpp.find(a2[i]) == mpp.end()){
            return "No";
        }
    }
    
    return "Yes";
}


// Another Solution

// Frequnecy of arra1 elements should be greater than or equal to the frequency of elements present in arr2

string isSubset(int a1[], int a2[], int n, int m) {
    map<int,int> mpp1;
    map<int,int> mpp2;
    
    for(int i=0;i<n;i++){
        mpp1[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        mpp2[a2[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(mpp1.find(a2[i]) == mpp1.end()){
            return "No";
        }
        if(mpp2[a2[i]] > mpp1[a2[i]])
        return "No";
    }
    
    return "Yes";
}