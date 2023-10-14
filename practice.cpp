#include<bits/stdc++.h>
using namespace std;

int solve(string str){
    int length= str.length();
    int i=0;
    int ans=INT_MAX,a=0;
    while(i<length){
        a++;
        if(str[i] == '@' || str[i]=='$'){
            ans = min ( ans ,a);
            a=0;
        }
        i++;
    }
    return min(ans,a);
}


int main(){
    string str="PPPPPP@PPP@PP$PP";
    cout<<solve(str);
    return 0;
}