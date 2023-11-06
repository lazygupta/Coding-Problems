#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    // Write your code here
    vector<vector<int>> ans;
    int j = 0;
    long long sum = 0;
    vector<int> temp;
    int i=0;
    // Sliding Window
    while(j<a.size()){
        sum+=a[j];
        temp.push_back(a[j]);
        
        while(sum>k && j<a.size()){
            sum -= a[i]; // subtract from begin of temp arr
            temp.erase(temp.begin(), temp.begin() + 1); // remove the first element from temp vector
            i++;
        }
        if(sum==k){
            ans.push_back(temp);
        }
        j++;
    }
    return ans;
}