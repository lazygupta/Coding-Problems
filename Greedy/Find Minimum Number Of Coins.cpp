// It was so simple
// You just have to take everytime the largest denomination
// And when the denomination is right smaller than the required amount, push it to result
// AGain check if that cavn fulfill the amount agian or not,If yes then push it agian
// Or else go to next smaller denomination

// O(N)

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
        else i++;
    }
    return res;
}