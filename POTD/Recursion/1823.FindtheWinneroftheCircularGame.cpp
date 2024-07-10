// O(N^2) Solution

class Solution {
public:

    void solve(int index,int k,vector<int> &v){
        if(v.size()==1){
            return;
        }
        index = (index+k)%v.size();
        v.erase(v.begin()+index);
        solve(index++,k,v);
    }

    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        solve(0,k-1,v);
        return v.back();
    }
};