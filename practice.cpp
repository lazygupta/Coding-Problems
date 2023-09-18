#include<bits/stdc++.h>
using namespace std;
int arya(int ar[],int n)
{
    // 2 2 4 5 6 8
    // a = 
    int a=0,b=0;
    for(int i=0;i<n;i+=2)
    {
        if(ar[i]%2!=0)//ar[4]
        {
            a+=ar[i];//1 => 8 => 11
            if(ar[i+1]%2!=0){
                b+=ar[i+1]; // 8 => 13
            }
            else{
                b+=ar[i+1];//2 => 8
                reverse(ar+(i+1),ar+n);
            }
        }
        else {
            a+=ar[i];//2
            reverse(ar+(i),ar+n);
            if(ar[i+1]%2!=0){
                b+=ar[i+1]; // 8 => 13
            }
            else{
                b+=ar[i+1];
                reverse(ar+(i+1),ar+n);
            }
        }
    }
    
    return (a>b);
}

int main(){
    int arr[6]={1,3,5,7,8,3};
    if(arya(arr,6)){
        cout<<"a is the winner"<<endl;
    }
    else cout<<"b is the winner"<<endl;
}