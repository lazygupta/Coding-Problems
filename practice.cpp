#include <bits/stdc++.h>
using namespace std;
void isSubset(int a1[], int a2[], int n, int m) {
    int a=0,count=0,j=0;
    a=max(n,m);
    for(int i=0;i<a;i++)//0-n
    {
        if(a2[j]==a1[i])
        {
            i=0;
            j++;//1
            count++;//1
        }
    }
    cout<<count<<endl;
    if(min(m,n)==count)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
}
int main()
{
    int n=6,m=4;
    int a1[6]={11, 1, 13, 21, 3, 7};
    int a2[4]={1, 3, 7, 11};
    isSubset(a1,a2,n,m);
   return 0;
}