// to print 1 to n

#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    solve(n-1);
    cout<<n<<" ";
}


int main(){
    int n=8;
    solve(n);
    return 0;
}


// Print N to 1


void solve(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    solve(n-1);
}

