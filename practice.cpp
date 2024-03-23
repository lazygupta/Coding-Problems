#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int arr[n];
        bool flag = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                flag = true;
                break;
            }
        }
        if( !flag || k>1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}