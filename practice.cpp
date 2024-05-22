#include <bits/stdc++.h>
using namespace std;
int arya(vector<int> v,int k)
{
    int j=0,m=0,result=0;
    
    for(int i=0;i<v.size();i++)
    {
        m=0;
        vector<int> v1;
        for(int l=0;l<k;l++)
        {
            v1.push_back(v[l+i]);
            m=max(m,v1.back());
            j++;
           
        }
        v1.clear();
        cout<<m;
    }
     return 0;
}
int main()
{
     vector<int> myvector{2,4,7,1,6,3};
     int k=3;
    arya(myvector,k);
    return 0;
}