// This question is of variable sized window
// Becasue the sum is not given

// Brute Force - O(N^3)
// Better Approach - O(N^2)


// Optimal Approach - Kadane's Algorithm
// TC - O(N)
// SC - O(1)


#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int v[], int n)
{
        int i=0;
        // if(v.size()==1) return v[0];
        long long sum=0;long long mx=INT_MIN;
        while(i<n){
            sum+=v[i];

            mx=max(mx,sum); // Storing the maximum sum and keeping the record

            if(sum<0) sum=0; // If at any position the sum becomes negative reset the sum to zero

            i++; // Increasing the pointer
        }
        return (mx<0)?0:mx;
}

// In the above question it may be asked 
// Print any subarray with maximum sum k

// In that case the modification


long long maxSubarraySum(int v[], int n)
{
        int i=0;
        // if(v.size()==1) return v[0];
        long long sum=0,start=0,ansStart,ansEnd;long long maxi=INT_MIN;
        while(i<n){
            if(sum==0) start=i;
            sum+=v[i];

            if(sum>maxi){ // Storing the maximum sum and keeping the record
                maxi=sum;
                ansStart= start;
                ansEnd = i;
            }

            if(sum<0) sum=0; // If at any position the sum becomes negative reset the sum to zero

            i++; // Increasing the pointer
        }

        cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << v[i] << " ";
    }
    cout << "]\n";
        return (maxi<0)?0:maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}