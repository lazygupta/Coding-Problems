#include<bits/stdc++.h>
using namespace std;

// Better Aproach

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
    if (n == 0) return 0;

    //sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
    }
};

// Optimal Approach
 

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n= a.size();
        if(n==0) return 0;
        int longest =1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        int count=0;
        for(auto it:st){
            if(st.find(it - 1) == st.end()){
                count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    count+=1;
                    x+=1;
                } 
            }
            longest = max ( longest , count);
        }

        return longest;
    }
};