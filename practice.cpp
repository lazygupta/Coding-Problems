#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int count_diff=0;
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                if(arr[j]-arr[i] == difference){
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                }
            }
        }
        vector<int> v1;
        for(auto x:v){
            if(find(v1.begin(),v1.end(),x) == v1.end()){
                v1.push_back(x);
            }
        }

        sort(v1.begin(),v1.end(),greater<int>());

        // for(auto x:v1){
        //     cout<<x<<" ";
        // }

        int count =0;
        for(int i=0;i<v1.size()-1;i++){
            if(!((v1[i+1] - v1[i]) == difference)){
                v1.erase(v1.begin()+(i+1));
            }
        }

        return v1.size();

        // 7 5 3 1 4 2
        // 7 5 4 3 2 1
        // 7 5 3 
    }
};

int main(){
    vector<int> v{1,2,3,4};
    Solution obj;
    cout<<obj.longestSubsequence(v,1);
    
    return 0;
}