#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    solve(n-1);
    
}


int main(){
    int n=8;
    solve(n);
    return 0;
}