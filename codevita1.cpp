#include<bits/stdc++.h>
using namespace std;
#define ll signed long long int

ll difference(vector<ll> v){
    list <ll> li;

    for(auto x:v){
        li.push_back(x);
    }
    ll p1=0,p2=0;
    int size= li.size() ;
    while(true){
        if(li.front()<=li.back() ){
            p1+=li.back();
            li.pop_back();
            while(li.front()<=li.back() && li.size()>size/2) {
                p1+=li.back();
            li.pop_back();
            }
        }
        else {
            p1+=li.front();
            li.pop_front();
            while(li.front()>=li.back() && li.size()>size/2){
                p1+=li.front();
            li.pop_front();
            }
        }
        if(li.empty()) break;

        if(li.front()<=li.back() ){
            p2+=li.back();
            li.pop_back();
            while(li.front()<=li.back() && li.size()>size/2){
                p2+=li.back();
            li.pop_back();
            }
        }
        else {
            p2+=li.front();
            li.pop_front();
            while(li.front()>=li.back() && li.size()>size/2){
                p2+=li.front();
            li.pop_front();
            }
        }

        if(li.empty()) break;
    }
    return p1-p2;
}

int main(){
    ll n;
    cin>>n;
    ll res;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        cin>>res;
        v.push_back(res);
    }
    cout<<difference(v);
    return 0;
}
