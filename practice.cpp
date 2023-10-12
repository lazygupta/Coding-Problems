#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int flag=0;
    for(auto it:v){
        if(it==1){
            cout<<"HARD";
            flag=1;
            break;
        }
    }
    if(flag==0) cout<<"EASY";
    return 0;
}