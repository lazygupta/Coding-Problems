#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // You need to complete this function
    void toh2(int N, int from, int to, int aux,long long &count) {
        count++;
        if(N==1){
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return;
        }
        toh2(N-1,from,aux,to,count);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh2(N-1,aux,to,from,count);
    }
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long count=0;
        toh2(N, from, to, aux, count);
        return count;
    }
    
};