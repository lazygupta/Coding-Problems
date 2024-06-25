// Same as Next Greater Element
// Start from right and instead of keeping record for index value, record index
// If the stack is not empty result will be stack_top - current_index

// O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                result[i] = st.top()-i;
            }
            st.push(i);
        }
        return result;
    }
};

