#include<bits/stdc++.h>
using namespace std;

void solved(stack<int> &st,int k){
   if(k==1){
      st.pop();
      return;
   }
   int temp=st.top();
   st.pop();
   solved(st,k-1);
   st.push(temp);
}


void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   if(inputStack.size()==0){
      return;
   }
   int temp;
   temp = (N/2) + 1 ;
   solved(inputStack,temp);
   return;
}