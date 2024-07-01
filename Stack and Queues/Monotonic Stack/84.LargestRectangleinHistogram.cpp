// Main aim is to find the nearest smallest element to the left and the right 
// as that would be the range of width we can extend for a bar

// Then we find length of left-right boundary as width and multiply it with width to get AREA of maxm ractangle

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> to_right(n,0);
        // Nearest Smaller to right - nle
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            to_right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int maxArea = 0;
        vector<int> to_left(n);
        st = stack<int>();
        // Nearest Smaller to left
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            to_left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int width = to_right[i] - to_left[i] - 1;
            maxArea = max(maxArea,heights[i] * width);
        }
        return maxArea;
    }
};