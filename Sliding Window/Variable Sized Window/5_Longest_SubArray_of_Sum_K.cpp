// The problem states that you are given an array of integers
// You have to find the longest sub array of sum k

// The problem can be done in O(n^2) in brute force solution


// I have solved this using Sliding Window Algorithm taking O(N) time complexity

// But the main problem is that my solution only works for the array containing only POSITIVE INTEGERS

#include<bits/stdc++.h>
using namespace std;

class Longest{
    public:

    int Longest_Subarray(vector<int> v,int k){
        int i=0,j=0;
        int sum=0,mx=0;
        while(j<v.size()){
            sum+=v[j];

            if(sum<k) j++;

            else if(sum==k){
                mx=max(mx,(j-i+1));
                j++;
            }

            else if(sum>k){
                sum-=v[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};


int main(){
    int n=17;
    //17 15
    vector<int> arr={-13,0,6, 15, 16, 2, 15, -12, 17, -16, 0 ,-3, 19, -3, 2, -9,-6};
    int k=15;
    Longest ob;
    int v1=ob.Longest_Subarray(arr,k);
    cout<<v1;
    return 0;
}


// Lets optimise it