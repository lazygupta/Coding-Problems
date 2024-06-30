// read the question first
// In this problem we can observe that we have no problem when we encounter a positive asteroid
// But as soon as negative asteroid comes it will try to cancel the last psoitive asteroid
// The conditions to cancel are:-
// If the last asteroid is less than the absolute of negative asteroid, Then the last asteroid will be removed
// If the last asteroid and abs(-ve asteroid) are equal then both will be cancelled i.e., yteh last asteroid will be removed and we will not consider the negative asteroid to enter the answer too
// The negative asteroid can only enter if the last element is negative 

// Remember if the asteroids are same magnitude then nothing will be done

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(asteroids[i] > 0 || st.size()==0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else{
                    if( st.empty() || st.top() < 0 ){
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        int size = st.size();
        vector<int> v(size,0);
        int i = 0;
        while(!st.empty()){
            v[size-i-1]=st.top();
            st.pop();
            i++;
        }

        return v;
    }
};