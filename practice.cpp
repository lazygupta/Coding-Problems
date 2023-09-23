#include<bits/stdc++.h>
using namespace std;

int prod (int arr[],int n,int index){
    int prod=1;
    for(int i=0;i<n;i++){
        if(i!=index){
            prod*=arr[i];
        }
    }
    return prod;
}

void result(int arr[],int n){
    int temp[n]={0};
    for(int i=0;i<n;i++){
        temp[i]=prod(arr,n,i);
    }
    for(int i=0;i<5;i++){
        cout<<temp[i]<<" ";
    }
}

int main(){
    int arr[5]={-1,1,0,-3,3};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    result(arr,5);
    cout<<endl;
}