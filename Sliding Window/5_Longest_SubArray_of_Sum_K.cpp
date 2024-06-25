// The problem states that you are given an array of integers
// You have to find the longest sub array of sum k

// The problem can be done in O(n^2) in brute force solution


// I have solved this using Sliding Window Algorithm taking O(N) time complexity

// But the main problem is that my solution not works for the array containing only positive negative and zeroes

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

            else if (sum>k){
                while(sum>k){
                    sum = sum - v[i];
                    i++;
                    if(sum==k){
                        mx = max(mx,(j-i+1));
                    }
                }
                j++;
            }
        }
        return mx;
    }
};


int main(){
    int n=-5;
    //17 15
    vector<int> arr={-5, 8, -14, 2, 4, 12};
    int k=3;
    Longest ob;
    int v1=ob.Longest_Subarray(arr,k);
    cout<<v1;
    return 0;
}


// 2nd Apporach 

// Using Hashing

// However this code with work for array containing zeroes or negative number
// Because mapping of sums is being replaced by index having zeroes 

// O(N^2)(Worst Case) - better Approach

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    map <long long , long long> mpp;
    int len=0; int maxlength=0;
    long long sum=0;
    for(int i=0;i<a.size();i++){
        sum+= a[i];

        if(sum==k) maxlength=max(maxlength,i+1);

        long long rem = sum -k ;
        
        if(mpp.find(rem) != mpp.end()){
            len = i - mpp[rem];
            maxlength = max (maxlength , len);
        }

        if(mpp.find(sum) == mpp.end()){ // Both for negative and zeroes
           mpp[sum] = i;
        }
    }
    return maxlength;
}

// To make it work for zereos and negative number both  the small change should be done
// We should map the sum value only if that sum was not in the map before

// So in above code

// At line 86

// if(mpp.find(sum) == mpp.end()){
//    mpp[sum] = i;
// }