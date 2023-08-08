#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int count=0,m=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(find(arr.begin(),arr.end(),i+1) == arr.end()){
                v.push_back(i);
            }
        }
        cout<<endl;
        return 0;
    }
};

int main()
{
    vector<int> arr{2,3,4,7,11 };
    int n = arr.size();
    // cout<<n<<endl;
    Solution obj;
    cout<<obj.findKthPositive(arr,5);
    // cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}