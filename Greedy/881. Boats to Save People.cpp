// Read question carefully
// Atmost two persons allowed
// Total weight should be less than limit


// Intuition :-
// Send the heaviest person with the lightest person

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boat=0;
        int i=0,j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <= limit){ // Send the lightest weighted person with the smallest weighted
                boat++;
                i++;
                j--;
            }
            else{ // If its over limit then send the largest one first
                boat++;
                j--;
            }
        }
        return boat;
    }
};

// 2nd approach
// Same as above
// Just less lines
// Sorting in descending order

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
        int boat=0;
        int i=0,j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <= limit) j--; // Send the lightest person only if satisfies
            i++; // Send the heaviest person everytime
        }
        // So if condition satisfies we are sending the lgihtest
        return i;
    }
};