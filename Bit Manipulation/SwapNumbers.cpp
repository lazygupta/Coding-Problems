#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=5,b=7;
    cout<<a<<" "<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<" "<<b;
}