// Given an array of N integers and Q queries of indices, print the number of next greater elements(NGEs) to the right of the given index element


class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int> result(indices.size());
       int k = 0;
    //   vector<int> nge(arr.size(),-1);
       stack<int> st;
       int count=0;
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && st.top()<arr[i]){
               st.pop();
           }
           if(!st.empty()){
               count++;
               if((i-1)==indices[k]) result[k]=count;
               k++;
           }
           st.push(arr[i]);
       }
       return result;
    }

};