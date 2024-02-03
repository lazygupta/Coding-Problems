#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    int start=0,end=4;
    while(start<=end/2){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    return 0;
}