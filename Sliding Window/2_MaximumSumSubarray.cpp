#include<bits/stdc++.h>
using namespace std;
class Maximum{
    public:
    int Max(int arr[],int size,int k){
        int sum=0,m=0,i=0,j=0;
        while(j<size){
            sum+=arr[j];

            if(j-i+1<k) j++;

            else if(j-i+1==k){
                m=max(sum,m);

                sum-=arr[i];

                i++;
                j++;

            }
        }
        return m;
    }

};

int main(){
    int n=6;
    int k=3;
    int arr[n]={1,5,6,7,2,1};
    Maximum obj;
    cout<<obj.Max(arr,n,k);
    return 0;
}