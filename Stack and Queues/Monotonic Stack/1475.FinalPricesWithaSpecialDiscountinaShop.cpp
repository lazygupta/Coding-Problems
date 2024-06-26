// Based on Next Smaller Element
// Very easy

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> output(n,0);
        int i=0;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() > prices[i]){ // Just check for oppposite as we are checking for NGE
                st.pop();
            }
            if(!st.empty()){
                output[i]=prices[i]-st.top();
            }
            else{
                output[i]=prices[i];
            }
            st.push(prices[i]);
        }
        return output;
    }
};