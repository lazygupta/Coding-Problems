// First sort the array according to values/weight

#include <bits/stdc++.h> 

bool comparator(pair<int, int>& item1,pair<int, int>& item2){
    double r1 = double(item1.second)/double(item1.first);
    double r2 = double(item2.second)/double(item2.first);
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comparator);
    double value=0;
    int curr_wt=0;
    for(int i=0;i<items.size();i++){
        if(curr_wt + items[i].first <= w){
            curr_wt += items[i].first;
            value += items[i].second;
        }
        else{
            double rem = w-curr_wt;
            value += (items[i].second/(double)items[i].first) * double(rem);
            break;
        }
    }
    return value;

}