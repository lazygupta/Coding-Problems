
void pushInBottom(stack<int> &st, int item){
    if(st.empty()){
        st.push(item);
        return;
    }
    if(st.top() < item){
        st.push(item);
        return;
    }
    int temp = st.top();
    st.pop();
    pushInBottom(st,item);
    st.push(temp);
}

void sortSt(stack<int> &st){
    if(st.empty()) return;
    
    int item = st.top();
    st.pop();
    sortSt(st);
    
    pushInBottom(st,item);
}

void SortedStack :: sort()
{
   //Your code here
   sortSt(s);
}