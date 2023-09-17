// Brute Force

// Same as 875 Koko eating bananas

// T.C = O(maxi-mini * N)


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maximum(vector<int> &v){
        int maximum=0;
        for(int i=0;i<v.size();i++){
            maximum = max (v[i], maximum);
        }
        return maximum;
    }

    int minimum(vector<int> &v){
        int minimum=INT_MAX;
        for(int i=0;i<v.size();i++){
            minimum = min (v[i], minimum);
        }
        return minimum;
    }

    int bouquet(vector<int> v,int days,int flowers_needed){
        int total_no=0;
        int count=0,maxi=0;
        for(int i=0;i<v.size();i++){
            if(days>=v[i]){
                count++;
            } 
            else{
                total_no+= count/flowers_needed;
                count=0;
            }
        }
        total_no+= count/flowers_needed;
        
        return total_no;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int No_of_Bouquet=0;
        for(int i=minimum(bloomDay);i<=maximum(bloomDay);i++){
            No_of_Bouquet = bouquet(bloomDay,i,k);
            if(No_of_Bouquet >= m){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<int> v{7,7,7,7,12,7,7};
    int m=2,k=3;
    cout<<obj.minDays(v, m, k);
    return 0;
}

// Binary search

// We know that our answer will be between minimum and maximum element
// We can think of binary search whenever answer is to be decided

class Solution {
public:

    int maximum(vector<int> &v){
        int maximum=INT_MIN;
        for(int i=0;i<v.size();i++){
            maximum = max (v[i], maximum);
        }
        return maximum;
    }

    int minimum(vector<int> &v){
        int minimum=INT_MAX;
        for(int i=0;i<v.size();i++){
            minimum = min (v[i], minimum);
        }
        return minimum;
    }

    bool bouquet(vector<int> v,int days,int flowers_needed,int m){
        int total_no=0;
        int count=0,maxi=0;
        for(int i=0;i<v.size();i++){
            if(days>=v[i]){
                count++;
            } 
            else{
                total_no+= count/flowers_needed;
                count=0;
            }
        }
        total_no+= count/flowers_needed;
        if(total_no>=m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = minimum(bloomDay);
        int high = maximum(bloomDay);
        int ans=-1;
        while(low<=high){
            int mid = low + (high - low)/2;

            if(bouquet(bloomDay,mid,k,m) == true){
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

