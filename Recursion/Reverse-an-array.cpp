// Print name 5 times

#include <bits/stdc++.h>
using namespace std;

class Names
{
public:
    void reverse(int i,int arr[],int n)
    {
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        reverse(i+1,arr,n);
    }
};

int main()
{
    Names obj;
    int n=5;
    int arr[n]={1,3,5,6,7};
    obj.reverse(0,arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}