// Brute Force Approach

// T.C = O(N)
// S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
    }
};

// Now we will try to optimize the space
// We dont need to store the sorted array into another array
// We just need the middle element if the total size of array is odd 
// And the element before the middle element if the total size of array is even

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size= nums1.size()+nums2.size(),ind1el=-1,ind2el=-1;
        int ind1=size/2,ind2=size/2-1;
        int i=0,j=0,cnt=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++;i++;
            }
            else{
                if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++;j++;
            }
        }
        while(i<nums1.size()) {
            if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++;i++;
        }
        while(j<nums2.size()) {
            if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++;j++;
        }
        if(size%2==1){
            return double(ind1el);
        }
        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};

