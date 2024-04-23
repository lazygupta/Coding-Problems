#include<bits/stdc++.h>
using namespace std;

int solve(int n,string str){
    int valley=0;
    int count=0;
    for(auto it:str){
        if(valley==0){
            count++;
        }
        if(it=='D'){
            valley--;
        }
        else{
            valley++;
        }
        
    }
    return count-1;
}

int main(){
    int n=8;
    string str = "DUUUDDDU";
    cout<<solve(n,str);
    return 0;
}