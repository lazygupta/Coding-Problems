#include<bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> v{1000,500,100,50,20,10,5,2,1};
    vector<int> res;
    int i=0;
    while(n!=0){
        if(n>=v[i]){
            res.push_back(v[i]);
            n-=v[i];
        }
    }
    return res;
}

int main(){
    int n=70;
    vector<int> v = MinimumCoins(n);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}