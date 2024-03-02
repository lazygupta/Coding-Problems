#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=5,b=7;
    cout<<a<<" "<<b<<endl;
    a=a^b; // a = 5^7
    b=a^b;// b = 5^7^7 = 5
    a=a^b; // a = 5^7^5 = 7
    cout<<a<<" "<<b;
}