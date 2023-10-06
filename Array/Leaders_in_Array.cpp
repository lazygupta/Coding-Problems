// Brute Force

// Select a element
// Iterate throught the array and check at any moment the right elemnent is greater than the selected element
// Then ignore it
// Otherwsie add it to your answer


#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    set<int> v;
    int maxi= a[a.size()-1];
    for(int i=a.size()-1;i>=0;i--){
      if(a[i]>=maxi){
        v.insert(a[i]);
        maxi = a[i];
      }
    }
    vector<int> vect{v.begin(),v.end()};
    return vect;
}

// Optimal Solution

// .. Start from the end
// Store the last element as the maximum
// Check from the back and store the maximum everytime


vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> v;
    int maxi= a[a.size()-1];
    v.push_back(maxi);
    for(int i=a.size()-1;i>=0;i--){
      if(a[i]>maxi){
        v.push_back(a[i]);
        maxi = a[i];
      }
    }
    return v;
}
