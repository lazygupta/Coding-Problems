


#include<bits/stdc++.h>
using namespace std;

vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int> ans;
    int mask = 1<<i-1;
    int temp = num;
    ans.push_back((temp&mask)?1:0);
    int set = mask|num;
    ans.push_back(set);
    int clear = ~(mask);
    ans.push_back(temp&clear);
    return ans;
}