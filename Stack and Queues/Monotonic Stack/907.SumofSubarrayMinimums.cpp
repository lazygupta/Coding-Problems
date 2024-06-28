// Think very sharply to solve this problem

// for every element we are finding the distnace between its nearest smaller element on left side
// And nearest smaller element on right side
// After finding the distance we are multiplying the bith distance and the element.
// We are doing so because for all the subarrays between the nearest small on left and the element the smallest will be the element itself same goes for right side

// Eg:- 0 3 4 5 2 3 4 1 4
// Now if we consider element 2 the subarray ranging from the extreme next smaller on left to extreme next smaller on right , The are:-
// 3 4 5 2 3 4
// Now for all the combinations of these subarrays the smallest will always be 2
// Lets see how

// Left :-
// 3 4 5 2
// 4 5 2
// 5 2

// Middle:-
// 2

// Right:-
// 2 3 4 
// 2 3
// Mix:-
// 3 4 5 2 3 4
// 3 4 5 2 3
// 4 5 2 3 4
// 5 2 3
// 4 5 2 3
// 5 2 3 4

// total 12 subarrays in which smaller element is always 2

// Now how to calculate it

// the nearest smaller element from element to left is at index 0 that is '0', distance = 4 - 9 = 4
// the nearest smaller element from element to right is at index 7 that is '1', distance = 7 - 4 = 3
// Multiplying we get, 4 * 3 = 12
// And final sum of these suybarrays will be = 2 * 12 = 24

// Likewise we have to find for all element

// We have to store -1 by default for every preSmaller Calculation
// We have to store n(Size of array) by default for every nextSmaller Calculation, as we will use to it substract the index traversing from the right side

typedef long long int ll;
class Solution {
public:

    vector<int> findPrevSmaller(vector<int> nums,int n){
        stack<int> st;
        vector<int> result(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> findNextSmaller(vector<int> nums,int n){
        stack<int> st;
        vector<int> result(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()) result[i]=st.top();
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre=findPrevSmaller(arr,n);
        vector<int> next=findNextSmaller(arr,n);
        ll mod = 1e9 + 7;
        ll sum =0;
        for(int i=0;i<n;i++){
            ll left = i - pre[i];
            ll right = next[i] - i;
            ll totalWays = left*right;
            ll totalSum = (arr[i] * totalWays)%mod;
            sum = (sum+totalSum)%mod;
        }
        return sum;
    }
};