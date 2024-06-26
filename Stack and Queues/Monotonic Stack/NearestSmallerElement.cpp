// Nearest Smaller Element same as Next smaller element

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> op(n,-1);
    for(int i=0;i<A.size();i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty()) op[i]=st.top();
        st.push(A[i]);
    }
    return op;
}
