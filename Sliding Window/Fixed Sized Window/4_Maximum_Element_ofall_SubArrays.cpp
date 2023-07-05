// So, The prblm states that you are given with an array of +ve and -ve numbers
// You just have to store all the maximum elements of all the subarrays of size k in an seperate array

//As we all know by seeing subarrays questions we can do it using Sliding Window Algorithm
// O(n) , where n is the size of the array

// This problem can be solve in O(n*k) by using Brute Force i.e., Nested for loop
// Here I am proceeding with the most optimal solution

//Auxillary Space = O(n-1) , n is the size of the array 

#include<bits/stdc++.h>
using namespace std;

vector<int> Maximum_Elements(int arr[], int n,int k){
    int i=0,j=0;
    int max_ele=INT_MIN;
    int sum=0;
    vector<int> v;
    while(j<n){
        max_ele=max(max_ele,arr[j]);
        if(j-i+1<k) j++;

        else if(j-i+1==k){ // Reaching the window size
            v.push_back(max_ele); //Pushing the maximum element uin that window

            if(max_ele == arr[i]){
                max_ele=INT_MIN;
                j=i+1;
                i++;
            }
            else{
            i++;
            j++;}
        }

    }
    return v;
}

int main(){
    int n=6;
    int arr[n]={5,4,1,0,6,3};
    int k=3;
    vector<int> v1=Maximum_Elements(arr,n,k);
    for(auto &it:v1)
    cout<<it<<" ";
    return 0;
}