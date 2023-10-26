#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int temp=st.top();
    st.pop();
    insert(st,ele);
    st.push(temp);
}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();
    reverse(st);
    insert(st,temp);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }
    reverse(stack);
}