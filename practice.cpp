#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==y && y==z) cout<<"YES"<<endl;
        else{
            int f1=0,f2=0,f3=0;
        while(x!=0){
            x=x-(x/2);
            if(x==1) f1=1;
        }
        while(y!=0){
            y=y-(y/2);
            if(y==1) f2=1;
        }
        while(z!=0){
            z=z-(z/2);
            if(z==1) f3=1;
        }
        if(f1==1 && f2==1 && f3==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    }
    return 0;
}