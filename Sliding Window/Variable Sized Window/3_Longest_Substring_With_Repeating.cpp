#include<bits/stdc++.h>
using namespace std;

class Longest{
    public:

    int Longest_Subarray(string v,int k){
        int i=0,j=0;
        int mx=-1;
        map<char,int> mpp;
        while(j<v.length()){
            mpp[v[j]]++;

            if(mpp.size()<k){
                j++;
            }

            else if(mpp.size()==k){
                mx=max(mx,j-i+1);
                j++;
            }

            if(mpp.size()>k){
                while(mpp.size()>k){
                    mpp[v[i]]--;
                    if(mpp[v[i]]==0) 
                    mpp.erase(v[i]);
                    i++;
                }
                j++;
            }

        }
        return mx;
    }
};


int main(){
    int n=7;
    //17 15
    string str="aabacbebebe";
    int k=3;
    Longest ob;
    int v1=ob.Longest_Subarray(str,k);
    cout<<v1;
    return 0;
}