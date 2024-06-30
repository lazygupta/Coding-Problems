// 907.Based on Sum of Subarrays minimum
// We have to find out sum of (maximum of all subarrys - minimum of all subarrays)
// So Sum(maximum of all subarry)  - Sum(minimum of all subarrays)

typedef long long int ll;
class Solution {
public:

    vector<int> ple(vector<int> nums,int n,int flag){
        stack<int> st;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && (flag ? nums[st.top()] > nums[i] : nums[st.top()] < nums[i] )){
                st.pop();
            }
            res[i] = (!st.empty()? st.top() : -1);
            st.push(i);
        }
        return res;
    }

    vector<int> nle(vector<int> nums,int n,int flag){
        stack<int> st;
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && (flag ? nums[st.top()] >= nums[i] : nums[st.top()] <= nums[i] )){
                st.pop();
            }
            res[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return res;
    }

    ll sumMinSubarrays(vector<int> nums,int n){
        vector<int> prevLessElement = ple(nums,n,1);
        vector<int> nextLessElement = nle(nums,n,1);
        ll sum =0;
        for(int i=0;i<n;i++){
            int leftElementDist = i - prevLessElement[i];
            int rightElementDist = nextLessElement[i] - i;
            ll totalWays = leftElementDist * rightElementDist;
            sum += nums[i] * totalWays;
        } 
        cout<<sum<<endl; 
        return sum;
    }

    ll sumMaxSubarrays(vector<int> nums,int n){
        vector<int> prevGreatElement = ple(nums,n,0);
        vector<int> nextGreatElement = nle(nums,n,0);
        ll sum =0;
        for(int i=0;i<n;i++){
            int leftElementDist = i - prevGreatElement[i];
            int rightElementDist = nextGreatElement[i] - i;
            ll totalWays = leftElementDist * rightElementDist;
            sum += nums[i] * totalWays;
        }  
        cout<<sum<<" ";
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
       return sumMaxSubarrays(nums,nums.size()) - sumMinSubarrays(nums,nums.size()); 
    }
};