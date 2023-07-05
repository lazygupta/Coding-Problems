// You have been given an Array filled with both positive and negative integers
// Your task is to find out the First occuring negative integer in a fixed subarray of size k

//This problem can be solved in O(N^2) using brute force solution
//However I made only optimal solution of this

// The solution is using SLiding Window Algorithm using O(n)
// I studied this from Aditya Verma


#include<bits/stdc++.h>
using namespace std;
void subarray(int ar[],int n,int k)
{
	int i=0,j=0;
	list<int> l;
	vector<int> v;
	while(j<n){
		if(ar[j]<0){ //Checking for the negative integer
			l.push_back(ar[j]); //Storing in the list 
		}
		if(j-i+1<k) j++; //Checking for the windows size reached or not
		else if(j-i+1==k){ //Windows su=ize reached
 			if(l.size()==0){
				v.push_back(0); //Storing 0 in a vector if list is empty in a window
			}
			else{
				v.push_back(l.front()); //Storing the first element in list in a vector
			}
			if(ar[i]==l.front()){ //Checking if the first array ele is equal to the list first element
				l.pop_front(); //Because we are going to increase i size
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