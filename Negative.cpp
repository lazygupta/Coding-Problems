// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
void subarray(int ar[],int n,int k)
{
	int i=0,j=0;
	list<int> l;
	vector<int> v;
	while(j<n){
		if(ar[j]<0){
			l.push_back(ar[j]);
		}
		if(j-i+1<k) j++;
		else if(j-i+1==k){
			if(l.size()==0){
				v.push_back(0);
			}
			else{
				v.push_back(l.front());
			}
			if(ar[i]==l.front()){
				l.pop_front();
			}
			j++;
			i++;
		}
	}
	for(auto x:v){
		cout<<x<<" ";
	}
}

    
int main()
{
    int m=8;
    int ar1[m]={12,-1,-7,8,-18,30,16,28};
    subarray(ar1,m,3);
    return 0;
}