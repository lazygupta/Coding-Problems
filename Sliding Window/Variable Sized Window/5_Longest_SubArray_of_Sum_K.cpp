#include<bits/stdc++.h>
using namespace std;

class Longest{
    public:

    int Longest_Subarray(vector<int> v,int k){
        int i=0,j=0;
        int sum=0,mx=0;
        while(j<v.size()){
            sum+=v[j];

            if(sum<k) j++;

            else if(sum==k){
                mx=max(mx,(j-i+1));
                j++;
            }

            else if(sum>k){
                sum-=v[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};


int main(){
    int n=7;
    vector<int> arr={4,1,1,1,1,1,5};
    int k=5;
    Longest ob;
    int v1=ob.Longest_Subarray(arr,k);
    cout<<v1;
    return 0;
}